#include "key.h"
#include "delay.h"

// 按键初始化
void keyInit(void) {
	PINSEL0 &= 0x0FFFFFFF;  // P0.14  P0.15
	PINSEL1 &= 0xFFFFFFFC;  // P0.16 
	IO0DIR |= ~(KEYS);  // 作为输入
}

unsigned char keyScan(void) {
	static unsigned char keyFlag = 0;
	// 两重检测
	if ((keyFlag == 0) && (((~IO0PIN & KEY1) == KEY1) || ((~IO0PIN & KEY2) == KEY2) || ((~IO0PIN & KEY3) == KEY3))) {
		if ((keyFlag == 0) && ((~IO0PIN & KEY1) == KEY1)) {
			keyFlag = 1;
			delay(1);  // 防抖
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
		// 所有按键都已经弹起
		keyFlag = 0;
	}
	return 0;
}


