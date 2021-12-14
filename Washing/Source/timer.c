#include "timer.h"
#include "CountDown.h"

void timer0Init(void){						// ��ʱ��0��ʼ��
	IRQEnable();							// ����IRQ�ж�
	T0TCR = 0x3;							// ��ʱ��0��TC��PC���ָ�λ  11
	T0PR = 0;								// Ԥ��ƵPRΪ0������Ƶ
	T0MCR = 0x003;       // ����MROƥ��ʱ�жϲ���λTC
	T0MR0 = Fpclk;					// ����TC�������ޣ���TC�ﵽ�������ޣ���λ
	
	VICIntSelect &= 0xFFFFFFEF;					// ͨ��4��Timer0�жϣ�����ΪIRQ�жϣ���ӦλΪ0��
	VICVectCntl0 = 0x20 | 0x04;				// bit[5]ʹ�ܣ�bit[4:0]ͨ��������ΪTimer0���ж�ͨ����4
	VICVectAddr0 = (uint32)IRQ_Timer0;		// �����жϷ�������ַ
	VICIntEnable = 1 << 4;				// ʹ��Timer0�ж�
	T0TCR = 0x1;							// ʹ�ܶ�ʱ��0���������λ
	return;
}


void __irq IRQ_Timer0(void){				//Timer0�жϷ������
	countDownNum -= 1;
	
	T0IR = 0x01;					// ���Timer0�жϱ�־�Ĵ���IR��bit[0]MR0
	VICVectAddr = 0x00;		// ֪ͨVIC�жϴ������

}


