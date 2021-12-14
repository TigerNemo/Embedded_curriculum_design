#include "motor.h"

void motorInit(void) {
	PINSEL0 &= 0xFFFF3FFF;  // P0.7����ΪPWM2
	PINSEL0 |= 0x00008000;  // P[15:14] ����Ϊ 10
	PWMPR = 0x00;  // PWM����Ƶ
	PWMMCR = 0x02;  // ����PWMMR0ƥ��ʱ��λPWMTC
	PWMPCR = 0x0400;  // ����PWM2�Ե����ӵ���ʽ���
	PWMMR0 = SPEED_MAX;  // ����PWMTC��������(PWMMR0)
	PWMMR2 = 0;  // ���ó�ʼռ�ձ�(�ٶ�)
	PWMLER = 0x05;  // PWM0��PWM2ƥ�����棬ʹPWMMR0��PWMMR2������Ч
	PWMTCR = 0x02;  // ��������λ��������ʹ��PWM
	PWMTCR = 0x09;  // ����PWM���
	PINSEL0 &= 0xFFFCFFFF;  // �������P0[8]GPIO�����ʼ��
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
	PWMLER = 0x05;  // ������ռ�ձ�֮��һ��Ҫ����д������ PWMLER
	return;
}
