deps_config := \
	/z/esp/esp-idf/components/app_trace/Kconfig \
	/z/esp/esp-idf/components/aws_iot/Kconfig \
	/z/esp/esp-idf/components/bt/Kconfig \
	/z/esp/esp-idf/components/driver/Kconfig \
	/z/esp/esp-idf/components/esp32/Kconfig \
	/z/esp/esp-idf/components/esp_adc_cal/Kconfig \
	/z/esp/esp-idf/components/esp_http_client/Kconfig \
	/z/esp/esp-idf/components/ethernet/Kconfig \
	/z/esp/esp-idf/components/fatfs/Kconfig \
	/z/esp/esp-idf/components/freertos/Kconfig \
	/z/esp/esp-idf/components/heap/Kconfig \
	/z/esp/esp-idf/components/http_server/Kconfig \
	/z/esp/esp-idf/components/libsodium/Kconfig \
	/z/esp/esp-idf/components/log/Kconfig \
	/z/esp/esp-idf/components/lwip/Kconfig \
	/z/esp/esp-idf/components/mbedtls/Kconfig \
	/z/esp/esp-idf/components/mdns/Kconfig \
	/z/esp/esp-idf/components/openssl/Kconfig \
	/z/esp/esp-idf/components/pthread/Kconfig \
	/z/esp/esp-idf/components/spi_flash/Kconfig \
	/z/esp/esp-idf/components/spiffs/Kconfig \
	/z/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/z/esp/esp-idf/components/vfs/Kconfig \
	/z/esp/esp-idf/components/wear_levelling/Kconfig \
	/z/esp/esp-idf/Kconfig.compiler \
	/z/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/z/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/Alex/mykaradio/main/Kconfig.projbuild \
	/z/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/z/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
