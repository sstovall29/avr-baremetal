#include <avr/io.h>

void initUSART(void);

void serialPrint(const char message[]);

void serialRead(char message[], int size);


