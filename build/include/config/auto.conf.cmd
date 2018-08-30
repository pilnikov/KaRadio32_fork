deps_config := \
	/home/pilnikov/esp/esp-idf/components/app_trace/Kconfig \
	/home/pilnikov/esp/esp-idf/components/aws_iot/Kconfig \
	/home/pilnikov/esp/esp-idf/components/bt/Kconfig \
	/home/pilnikov/esp/esp-idf/components/driver/Kconfig \
	/home/pilnikov/esp/esp-idf/components/esp32/Kconfig \
	/home/pilnikov/esp/esp-idf/components/esp_adc_cal/Kconfig \
	/home/pilnikov/esp/esp-idf/components/esp_http_client/Kconfig \
	/home/pilnikov/esp/esp-idf/components/ethernet/Kconfig \
	/home/pilnikov/esp/esp-idf/components/fatfs/Kconfig \
	/home/pilnikov/esp/esp-idf/components/freertos/Kconfig \
	/home/pilnikov/esp/esp-idf/components/heap/Kconfig \
	/home/pilnikov/esp/esp-idf/components/http_server/Kconfig \
	/home/pilnikov/esp/esp-idf/components/libsodium/Kconfig \
	/home/pilnikov/esp/esp-idf/components/log/Kconfig \
	/home/pilnikov/esp/esp-idf/components/lwip/Kconfig \
	/home/pilnikov/esp/esp-idf/components/mbedtls/Kconfig \
	/home/pilnikov/esp/esp-idf/components/mdns/Kconfig \
	/home/pilnikov/esp/esp-idf/components/openssl/Kconfig \
	/home/pilnikov/esp/esp-idf/components/pthread/Kconfig \
	/home/pilnikov/esp/esp-idf/components/spi_flash/Kconfig \
	/home/pilnikov/esp/esp-idf/components/spiffs/Kconfig \
	/home/pilnikov/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/home/pilnikov/esp/esp-idf/components/vfs/Kconfig \
	/home/pilnikov/esp/esp-idf/components/wear_levelling/Kconfig \
	/home/pilnikov/esp/esp-idf/Kconfig.compiler \
	/home/pilnikov/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/pilnikov/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/pilnikov/examples/MyKaradio/main/Kconfig.projbuild \
	/home/pilnikov/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/pilnikov/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
