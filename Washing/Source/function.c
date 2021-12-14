#include "function.h"
#include "led.h"
#include "beep.h"
#include "motor.h"
#include "key.h"

volatile unsigned char flag = 0;

// 慢洗功能
void functionModel1(void) {
	led0Off();
	led1On();
	countDownNum = 9;
	while (countDownNum != 0) {
		motorSpeed(countDownNum & 0x02 ? SPEED_MIN : -SPEED_MIN);
		digitalTubeShow(countDownNum);
	}
	digitalTubeShow0();
	motorSpeed(0);
	led1Off();
	beepTimes(3);
	led0On();
	return;
}

// 快洗功能
void functionModel2(void) {
	led0Off();
	led2On();
	countDownNum = 6;
	while (countDownNum != 0) {
		motorSpeed(countDownNum & 0x02 ? SPEED_MID : -SPEED_MID);
		digitalTubeShow(countDownNum);
	}
	digitalTubeShow0();
	motorSpeed(0);
	led2Off();
	beepTimes(3);
	led0On();
	return;
}

// 脱水功能
void functionModel3(void) {
	led0Off();
	led3On();
	countDownNum = 5;
	while (countDownNum != 0) {
		motorSpeed(-SPEED_MAX);
		digitalTubeShow(countDownNum);
	}
	digitalTubeShow0();
	motorSpeed(0);
	led3Off();
	beepTimes(3);
	led0On();
	return;
}

void menu(void) {
	flag = keyScan();
}

