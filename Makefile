PROJECT = AlarmClock
BOARD = atmega2560
TARGET = build/main
PORT =  /dev/cu.usbmodem2131201
# SRC = $(wildcard src/*.cpp)
SRC = \
    src/main.cpp \
    src/gpio.cpp \
    src/timer.cpp

OBJ = \
    build/main.o \
    build/gpio.o \
    build/timer.o

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



# all:	
# 	echo "Building $(PROJECT)..."
# 	mkdir -p build
# 	avr-g++ \
# 	-mmcu=$(BOARD) \
# 	-DF_CPU=16000000UL \
# 	-Iinclude \
# 	$(SRC)	\
# 	-o $(TARGET).elf
# 	avr-objcopy -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex
# 	avr-size --mcu=$(BOARD) --format=avr $(TARGET).elf

