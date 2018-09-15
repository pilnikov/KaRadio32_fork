// ----------------------------------------------------------------------------
// Rotary Encoder Driver with Acceleration
// Supports Click, DoubleClick, Long Click
//
// (c) 2010 karl@pitrich.com
// (c) 2014 karl@pitrich.com
// 
// Timer-based rotary encoder logic by Peter Dannegger
// http://www.mikrocontroller.net/articles/Drehgeber
// ----------------------------------------------------------------------------
#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include "ClickEncoder.h"
#include "app_main.h"
#include "gpio.h"
#include "webclient.h"
#include "webserver.h"
#include "interface.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


// ----------------------------------------------------------------------------
// Button configuration (values for 1ms timer service calls)
//
#define ENC_BUTTONINTERVAL    10  // check button every x milliseconds, also debouce time


// ----------------------------------------------------------------------------

  int8_t pinBTN[3];
  bool pinsActive;

  volatile Button button[3];
  bool doubleClickEnabled;
  bool buttonHeldEnabled;
  bool buttonOnPinZeroEnabled = false;
  uint16_t keyDownTicks[3] = {0, 0, 0};
  uint16_t doubleClickTicks[3] = {0, 0, 0};
  uint16_t buttonHoldTime = BTN_HOLDTIME;
  uint16_t buttonDoubleClickTime = BTN_DOUBLECLICKTIME;
  unsigned long lastButtonCheck[3] = {0, 0, 0};


#define TAG "ClickEncoder"
#define GPIO_INPUT_PIN_SEL  ((1ULL<<PIN_ENC_A) | (1ULL<<PIN_ENC_B) | (1ULL<<PIN_ENC_BTN))
#define ESP_INTR_FLAG_DEFAULT 0


void noInterrupts()
{noInterrupt1Ms();}

void interrupts()
{interrupt1Ms();}


// ----------------------------------------------------------------------------

bool getpinsActive() {return pinsActive;}

void ClickEncoderInit(int8_t A, int8_t B, int8_t BTN)
{
   pinBTN[1] = A; pinBTN[2] = B; pinBTN[0] = BTN;
   pinsActive = LOW; button[0] = Open; button[1] = Open; button[2] = Open;
   doubleClickEnabled = true; buttonHeldEnabled = true;
	
   gpio_config_t gpio_conf;
   //disable interrupt
   
   //interrupt of rising edge
   gpio_conf.intr_type = GPIO_PIN_INTR_NEGEDGE;
   //bit mask of the pins, 
   gpio_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
   //set as input mode    
   gpio_conf.mode = GPIO_MODE_INPUT;
   gpio_config(&gpio_conf);
}

// ----------------------------------------------------------------------------
// call this every 1 millisecond via timer ISR
//
void (*serviceEncoder)() = NULL;
void service(void)
{
/*  bool moved = false;

  if (pinA >= 0 && pinB >= 0) {
  if (accelerationEnabled) { // decelerate every tick
    acceleration -= ENC_ACCEL_DEC;
    if (acceleration & 0x8000) { // handle overflow of MSB is set
      acceleration = 0;
    }
  }

#if ENC_DECODER == ENC_FLAKY
  last = (last << 2) & 0x0F;

  if (digitalRead(pinA) == pinsActive) {
    last |= 2;
  }

  if (digitalRead(pinB) == pinsActive) {
    last |= 1;
  }

  int8_t tbl = pgm_read_byte(&table[last]); 
  if (tbl) {
    delta += tbl;
    moved = true;
  }
#elif ENC_DECODER == ENC_NORMAL
  int8_t curr = 0;

  if (digitalRead(pinA) == pinsActive) {
    curr = 3;
  }

  if (digitalRead(pinB) == pinsActive) {
    curr ^= 1;
  }
  
  int8_t diff = last - curr;

  if (diff & 1) {            // bit 0 = step
    last = curr;
    delta += (diff & 2) - 1; // bit 1 = direction (+/-)
    moved = true;    
  }
#else
# error "Error: define ENC_DECODER to ENC_NORMAL or ENC_FLAKY"
#endif

  if (accelerationEnabled && moved) {
    // increment accelerator if encoder has been moved
    if (acceleration <= (ENC_ACCEL_TOP - ENC_ACCEL_INC)) {
      acceleration += ENC_ACCEL_INC;
    }
  }
}
 */
  // handle button
  //
  unsigned long currentMillis = xTaskGetTickCount()* portTICK_PERIOD_MS;
  for(uint8_t i = 0; i < 3; i++) 
  {
	  if (currentMillis < lastButtonCheck[i]) lastButtonCheck[i] = 0;        // Handle case when millis() wraps back around to zero
	  if ((pinBTN[i] > 0 || (pinBTN[i] == 0 && buttonOnPinZeroEnabled))        // check button only, if a pin has been provided
		  && ((currentMillis - lastButtonCheck[i]) >= ENC_BUTTONINTERVAL))            // checking button is sufficient every 10-30ms
	  { 
		lastButtonCheck[i] = currentMillis;

		bool pinRead = getPinState(i);
		
		if (pinRead == pinsActive) { // key is down
		  keyDownTicks[i]++;
		  if ((keyDownTicks[i] > (buttonHoldTime / ENC_BUTTONINTERVAL)) && (buttonHeldEnabled)) {
			button[i] = Held;
		  }
		}

		if (pinRead == !pinsActive) { // key is now up
		  if (keyDownTicks[i] > 1) {               //Make sure key was down through 1 complete tick to prevent random transients from registering as click
			if (button[i] == Held) {
			  button[i] = Released;
			  doubleClickTicks[i] = 0;
			}
			else {
			  #define ENC_SINGLECLICKONLY 1
			  if (doubleClickTicks[i] > ENC_SINGLECLICKONLY) {   // prevent trigger in single click mode
				if (doubleClickTicks[i] < (buttonDoubleClickTime / ENC_BUTTONINTERVAL)) {
				  button[i] = DoubleClicked;
				  doubleClickTicks[i] = 0;
				}
			  }
			  else {
				doubleClickTicks[i] = (doubleClickEnabled) ? (buttonDoubleClickTime / ENC_BUTTONINTERVAL) : ENC_SINGLECLICKONLY;
			  }
			}
		  }

		  keyDownTicks[i] = 0;
		}
	  
		if (doubleClickTicks[i] > 0) {
		  doubleClickTicks[i]--;
		  if (doubleClickTicks[i] == 0) {
			button[i] = Clicked;
		  }
		}
	  }

  }
}
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
Button getButton(uint8_t index)
{
  noInterrupts();
  Button ret = button[index];
  if (button[index] != Held && ret != Open) {
    button[index] = Open; // reset
  }
  interrupts();
  return ret;
}



bool getPinState(uint8_t index) {
  bool pinState = digitalRead(pinBTN[index]);
  return pinState;
}

  

