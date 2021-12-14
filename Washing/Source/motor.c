#include "motor.h"

void motorInit(void) {
	PINSEL0 &= 0xFFFF3FFF;  // P0.7配置为PWM2
	PINSEL0 |= 0x00008000;  // P[15:14] 设置为 10
	PWMPR = 0x00;  // PWM不分频
	PWMMCR = 0x02;  // 设置PWMMR0匹配时复位PWMTC
	PWMPCR = 0x0400;  // 允许PWM2以单边延的形式输出
	PWMMR0 = SPEED_MAX;  // 设置PWMTC计数上限(PWMMR0)
	PWMMR2 = 0;  // 设置初始占空比(速度)
	PWMLER = 0x05;  // PWM0和PWM2匹配锁存，使PWMMR0与PWMMR2设置生效
	PWMTCR = 0x02;  // 启动并复位计数器，使能PWM
	PWMTCR = 0x09;  // 启动PWM输出
	PINSEL0 &= 0xFFFCFFFF;  // 方向控制P0[8]GPIO输出初始化
	IO0DIR |= DIRECTION;  
	motorSpeed(0);
	return;
}

void motorSpeed(int speed) {
	if (speed >= 0) {
		IO0CLR = DIRECTION;  // 0V
		PWMMR2 = speed;  // 2.3V
	} else {
		IO0SET = DIRECTION;  // 3.3V
		PWMMR2 = SPEED_MAX + speed;   // 1V
	}
	PWMLER = 0x05;  // 配置完占空比之后一定要重新写入锁存 PWMLER
	return;
}
