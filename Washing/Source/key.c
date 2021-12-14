#include "key.h"
#include "delay.h"

// ������ʼ��
void keyInit(void) {
	PINSEL0 &= 0x0FFFFFFF;  // P0.14  P0.15
	PINSEL1 &= 0xFFFFFFFC;  // P0.16 
	IO0DIR |= ~(KEYS);  // ��Ϊ����
}

unsigned char keyScan(void) {
	static unsigned char keyFlag = 0;
	// ���ؼ��
	if ((keyFlag == 0) && (((~IO0PIN & KEY1) == KEY1) || ((~IO0PIN & KEY2) == KEY2) || ((~IO0PIN & KEY3) == KEY3))) {
		if ((keyFlag == 0) && ((~IO0PIN & KEY1) == KEY1)) {
			keyFlag = 1;
			delay(1);  // ����
			return keyFlag;
		} else if ((keyFlag == 0) && ((~IO0PIN & KEY2) == KEY2)) {
			keyFlag = 2;
			delay(1);
			return keyFlag;
		} else if ((keyFlag == 0) && ((~IO0PIN & KEY3) == KEY3)) {
			keyFlag = 3;
			delay(1);
			return keyFlag;
		}
	}
	if (keyFlag && ((IO0PIN & KEYS) == KEYS)) {
		// ���а������Ѿ�����
		keyFlag = 0;
	}
	return 0;
}


