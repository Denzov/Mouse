simulation: build 
	C:\Users\user\.platformio\packages\tool-simavr\bin\simavr.exe -m atmega328p -f 16000000 .pio/build/nanoatmega328/firmware.elf

build:
	pio run

simulation_raw:
	C:\Users\user\.platformio\packages\tool-simavr\bin\simavr.exe -m atmega328p -f 16000000 .pio/build/nanoatmega328/firmware.elf