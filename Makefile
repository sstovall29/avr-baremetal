PROJECT = AlarmClock
BOARD = atmega328P
TARGET = build/main
PORT =  /dev/cu.usbmodem21314101

SRC = \
    main.cpp \

.PHONY: all flash clean 

all:	
	echo "Building $(PROJECT)..."
	mkdir -p build
	avr-g++ \
	-mmcu=$(BOARD) \
	-DF_CPU=16000000UL \
	-Iinclude \
	$(SRC)	\
	-o $(TARGET).elf
	avr-objcopy -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex
	avr-size --mcu=$(BOARD) --format=avr $(TARGET).elf

flash:
	echo "Uploading"
	avrdude \
	-D \
	-p $(BOARD) \
	-c wiring \
	-P $(PORT) \
	-b 115200 \
	-U flash:w:$(TARGET).hex:i
	
clean:
	echo "cleaning"
	rm -rf build
