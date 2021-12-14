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
	ledInit();  // LED灯初始化
	digitalTubeInit();  // 数码管初始化
	timer0Init();  // 定时器初始化
	beepInit();  // 蜂鸣器初始化
	motorInit();  // 电机初始化
	keyInit();  // 键盘初始化
	uart0Init();  // 串口初始化
	

	
	while (1) {

		menu();
		if (rcv_new == 1) {  // 串口入口
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
			case 0: led0On(); break;  // 待机状态
			case 1: functionModel1(); break;
			case 2: functionModel2(); break;
			case 3: functionModel3(); break;
		}
	}
	
	
}

