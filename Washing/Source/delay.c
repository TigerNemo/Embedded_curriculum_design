#include "delay.h"

void delay(uint32 times){						//Èí¼þÑÓÊ±
	uint32 i = 0;
	for ( ; times>0; times--)
		for (i=0; i<DELAY; i++);
	return;
}
