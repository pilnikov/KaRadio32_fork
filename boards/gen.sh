#!/bin/bash
filename=$(basename "$1")
fname="${filename%.*}"
echo python ./gen.py --input ${fname}.csv --output build/${fname}.bin --size 0x3000 --version v1
python ./gen.py --input ${fname}.csv --output build/${fname}.bin --size 0x3000 --version v1
echo write flash....
python ./esptool.py --chip esp32 --port com5 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 40m --flash_size detect 0x3a2000 build/${fname}.bin
echo done
