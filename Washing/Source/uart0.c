#include "uart0.h"
#include "string.h"

volatile uint8 rcv_new = 0;
volatile char rcv_buf[8];
volatile uint8 uart0Flag = 0;
const char tmp1[8] = "Model_1";
const char tmp2[8] = "Model_2";
const char tmp3[8] = "Model_3";
char tmp[8];

void uart0Init() {
	PINSEL0 &= 0xFFFFFFF0;
	PINSEL0 |= 0x00000005;  // ���� GPIO[1:0] ���ӵ�uart0
	
	U0LCR = 0x80;  // ͨ�������ʼ���
	U0DLM = 0x00;
	U0DLL = 0x5A;
	
	U0LCR = 0x03;
	U0FCR = 0x81;  // ʹ��FIFO�������ô�����Ϊ8���ֽ�
	U0IER = 0x01;  // ����RBR�жϣ��������ж�
	
	VICIntEnable |= 1 << 0x06;  // ʹ��UART0�ж�, #UART0_INT = 6;
	VICIntSelect &= 0xFFFFFFBF;  // �жϺ�6
	VICVectCntl2 = 0x20 | 0x06;  // uart0���䵽IRQ slot0����������ȼ�
	VICVectAddr2 = (uint32)IRQ_Uart0;  // �жϷ������
}

void __irq IRQ_Uart0() {
	uint8 i;
	if ((U0IIR & 0x0F) == 0x04)	{	// IIR[0]==0,��UART_INT��IIR[3:1]==010,UART��������INT
		rcv_new = 1;				// ���ý��յ��µ����ݱ�־
		}
	for (i=0; i<7; i++)
		rcv_buf[i] = U0RBR;
	rcv_buf[7] = '\0';
	for (i=0; i<8; i++)
		tmp[i] = rcv_buf[i];
	if (strcmp(tmp, tmp1) == 0) {
		uart0Flag = 1;
	} else if (strcmp(tmp, tmp2) == 0) {
		uart0Flag = 2;
	} else if (strcmp(tmp, tmp3) == 0) {
		uart0Flag = 3;
	} else {
		uart0Flag = 0;
	}
	VICVectAddr = 0x00;				// �жϴ������
}


void UART0_SendBuf (void)
{
	uint8 i;
	for (i=0; i<8; i++) {
		tmp[i] = rcv_buf[i];
		UART0_SendByte(tmp[i]);
	}
	UART0_SendByte(0x0d);
	UART0_SendByte(0x0a);
}
void UART0_SendByte (uint8 dat)
{
	U0THR = dat;	// Ҫ���͵�����
}
