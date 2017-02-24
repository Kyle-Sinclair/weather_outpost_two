#include <stdint.h>
#include <pic32mx.h>
#include "master.h"

int getsw(void){
	int switchData = ((PORTD & 0x00000f00) >> 8);
	return switchData;
}

int getbtns(void){
	int buttonData = ((PORTD >> 5) & 0x7);
	return buttonData;
}
