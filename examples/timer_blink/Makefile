PROJECT = timer_blink
BOARD = atmega328p
TARGET = build/main
PORT =  /dev/cu.usbmodem2131101
MODULES = ../../modules

SRC = \
    main.cpp \
		$(MODULES)/gpio/gpio.cpp

.PHONY: all flash clean 

all:	
	echo "Building $(PROJECT)..."
	mkdir -p build
	avr-g++ \
	-mmcu=$(BOARD) \
	-DF_CPU=16000000UL \
	-I$(MODULES) \
	$(SRC)	\
	-o $(TARGET).elf
	avr-objcopy -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex
	avr-size --mcu=$(BOARD) --format=avr $(TARGET).elf

flash:
	echo "Uploading"
	avrdude \
	-p $(BOARD) \
	-c arduino \
	-P $(PORT) \
	-b 115200 \
	-U flash:w:$(TARGET).hex:i
	
clean:
	echo "cleaning"
	rm -rf build
