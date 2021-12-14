#include "lpc213x.h"
#include "TypeDef.h"
#include "delay.h"
#include "led.h"
#include "timer.h"
#include "digitaltube.h"
#include "CountDown.h"
#include "function.h"
#include "beep.h"
#include "motor.h"
#include "key.h"
#include "uart0.h"


int main(){
	ledInit();  // LED�Ƴ�ʼ��
	digitalTubeInit();  // ����ܳ�ʼ��
	timer0Init();  // ��ʱ����ʼ��
	beepInit();  // ��������ʼ��
	motorInit();  // �����ʼ��
	keyInit();  // ���̳�ʼ��
	uart0Init();  // ���ڳ�ʼ��
	

	
	while (1) {

		menu();
		if (rcv_new == 1) {  // �������
			UART0_SendBuf();
			switch (uart0Flag) {
				case 0: flag = 0; break;
				case 1: flag = 1; break;
				case 2: flag = 2; break;
				case 3: flag = 3; break;
			}
			
			rcv_new = 0;
		}
		
		switch (flag) {
			case 0: led0On(); break;  // ����״̬
			case 1: functionModel1(); break;
			case 2: functionModel2(); break;
			case 3: functionModel3(); break;
		}
	}
	
	
}

