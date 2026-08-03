# avr-baremetal

## Description
This template is meant to be the starting point for embedded projects based on programming an AVR microcontroller with the AVR-GCC toolchain and a custom Makefile.
This template is build without the Arduino framework so none of the Arduino functions will work. Hardware is controlled directly through AVR registers and peripherals. 

## Project Structure
src/
  main.cpp    // Application entry point

include/      // Header files

build/        // Generated build artifacts

Makefile      // Build and upload commands

## Usage
1. In the Makefile, change the BOARD and PORT your hardware
2. Put your man code in the src/main.cpp file
3. Build the project:
  **make**
Run **make** to compile, link, and convert the files
4. Flash the compiled program to the board
 **make flash**
6 Remove generated files from /build
  **make clean**

## Build Pipeline
main.cpp
    ↓
avr-g++
    ↓
main.elf
    ↓
avr-objcopy
    ↓
main.hex
    ↓
avrdude
    ↓
AVR Microcontroller


## Notes
- This template is intended for learning and bare-metal development.
- No Arduino libraries are linked.
- Additional source files should be placed in src/, with headers in include/.
- Compiler flags, optimization levels, and upload settings can be modified in the Makefile as needed.
