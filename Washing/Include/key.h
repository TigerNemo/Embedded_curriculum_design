#include "TypeDef.h"
#include "lpc213x.h"

// ������GPIO�Ķ�Ӧ��ϵ
#define KEY1 ((uint32)(1 << 16))
#define KEY2 ((uint32)(1 << 14))
#define KEY3 ((uint32)(1 << 15))
#define KEYS ((uint32)(7 << 14))

// �����ź�
#define KEY1_F ((unsigned char)(0x01))
#define KEY2_F ((unsigned char)(0x02))
#define KEY3_F ((unsigned char)(0x03))

void keyInit(void);  // ������ʼ��
unsigned char keyScan(void);  // ��ⰴ����ɨ��ķ�ʽ
