#include "digitaltube.h"

void digitalTubeInit(void) {
	PINSEL1 &= 0x0003FFFF;
	IO0DIR |= DIGITALTUBE_GPIO;
	IO0CLR |= DIGITALTUBE_GPIO;
	return;
}

void digitalTubeShow(unsigned char num) {
	switch (num) {
		case 0: digitalTubeShow0(); break;
		case 1: digitalTubeShow1(); break;
		case 2: digitalTubeShow2(); break;
		case 3: digitalTubeShow3(); break;
		case 4: digitalTubeShow4(); break;
		case 5: digitalTubeShow5(); break;
		case 6: digitalTubeShow6(); break;
		case 7: digitalTubeShow7(); break;
		case 8: digitalTubeShow8(); break;
		case 9: digitalTubeShow9(); break;
	}
}

