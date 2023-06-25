#include "NoaFunc.h"
#include "stdio.h"
#include "NoaCode.h"
#include "type.h"
#include "NoaMath.h"


//void version(RAM* ram, int64 dpIndex, int64 dpLength, int* pcIndex) {
//	printf("NoaVM version:0.0.1\n");
//}
//

void PrintString(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
) {
	for (int64 i = noaRegister[2]; i < noaRegister[2] + noaRegister[3];i++) {
		printf("%c",ram->buffer[i]);
	}
	(*pcIndex) = (*pcIndex) + 1;
}


void PrintRegister(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
	)
{
	//��ӡ�Ĵ��������ֵ
	switch (paramer2)
	{
		case 0x80:
			//��ӡ�ַ�
			printf("%c",noaRegister[paramer1]);
			break;
		case 0x81:
			printf("%d", noaRegister[paramer1]);
			break;
		default:
			break;
	}
	(*pcIndex) = (*pcIndex) + 3;
}

void MoveToRegister(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
)
{
	//printf("movָ��ִ�����\n");
	//��ram��λ��ΪdpIndex�����ݷ���Ĵ�����
	noaRegister[paramer1] = paramer2;
	(*pcIndex) = (*pcIndex) + 3;
	
}
//

uint8 AddB(uint8 a, uint8 b) {
	uint8 y = a;
	while (b) {
		uint8 tmp = a;
		a = a ^ b;
		b = (tmp & b) << 1;
		y = a;
	}
	return y;
}

void AddByte(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
)
{
	//ʹ��addǰ��������ʹ��movָ����ַŵ��Ĵ����ڲ�
	noaRegister[paramer1] = AddB(noaRegister[paramer1],noaRegister[paramer2]);
	(*pcIndex) = (*pcIndex) + 3;
}

void Sub(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
) {
	noaRegister[paramer1] -= noaRegister[paramer2];
	(*pcIndex) = ((*pcIndex) + 3);
}

//
//void ASubB(RAM* ram, int64 adresss1, int64 adresss2, int* pcIndex)
//{
//	//��������
//	noaRegister[adresss1] -= noaRegister[adresss2];
//}
//
//void noaAnd(RAM* ram, int64 adress1, int64 adress2, int* pcIndex)
//{
//	//������
//	noaRegister[adress1] = (noaRegister[adress1] & noaRegister[adress2]);
//}
//
//void heapToRAM(RAM* ram, int64 pramater1, int64 data, int* pcIndex)
//{	//mov,ecx,pos
//	//mov,edx,len
//	//mst,
//	/*int64 heapPos = noaRegister[2];
//	int64 length = noaRegister[3];
//	for(int64 i=0;i<length;i++)
//	{
//		ram->buffer[i] = noaHeap[heapPos][i];
//	}*/
//	
//}
//
void WriteToRAM(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
)
{
	//���ڱ�������õ�
	//int adress = paramer1 * (16777216) + paramer2 * (65535) + paramer3 * (256) + paramer4;
	//ram->buffer[adress] = paramer5;
	//(*pcIndex) = (*pcIndex) + 6;
	ram->buffer[paramer1] = paramer2;
	(*pcIndex) = (*pcIndex) + 3;
}

extern void ReadFromRAM(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
)
{
	//�ڴ��ַռ4λ
	//���ڴ��ȡ���ݵ��Ĵ�����
	//rfm eax a
	/*int adress = paramer2 * (16777216) + paramer3 * (65535) + paramer4 * (256) + paramer5;
	noaRegister[paramer1] = ram->buffer[adress];
	(*pcIndex) = (*pcIndex) + 6;*/
	noaRegister[paramer1] = ram->buffer[paramer2];
	(*pcIndex) = (*pcIndex) + 3;
}

//
//void noaOr(RAM* ram, int64 adress1, int64 adress2, int* pcIndex)
//{
//	noaRegister[adress1] = (noaRegister[adress1] | noaRegister[adress2]);
//}
//
//void multiply(RAM* ram, int64 adress1, int64 adress2, int* pcIndex) {
//	noaRegister[adress1] *= noaRegister[adress2];
//}
//void divide(RAM* ram, int64 adress1, int64 adress2, int* pcIndex) {
//	if (noaRegister[adress2]==0) {
//		noaRegister[adress1] = 0xffffffff;
//		return;
//	}
//
//	noaRegister[adress1] /= noaRegister[adress2];
//
//}
//

//�涨�����ĵ�ַ������ݵĵ�ַ�붼Ϊ4B

void CallCode(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
) {
	//��ջ
	int64 nextPos = ((*pcIndex) + 5);
	//printf("��ջ��ַ:%d\n", nextPos);
	PushCodeStack(callStack, nextPos);
	
	//������ַ
	uint8 code[4];
	code[0] = paramer1;
	code[1] = paramer2;
	code[2] = paramer3;
	code[3] = paramer4;
	int64 funcHashCode = HashCode(code,4,0,4096);
	FuncNode* func = GetFunc(&funcTable,funcHashCode);
	//����λ�ö�λ�����㷨
	int64 funcIndex = func->pcIndex;
	(*pcIndex) = funcIndex;
	//printf("\n[warring]:���ú���,����ַΪ:%x %x %x %x��pc : %d\n", paramer1, paramer2, paramer3, paramer4,(*pcIndex));

}
//
void ReturnCode(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
) 
{
	//�ָ��ֳ�
	//recall
	int64 returnIndex = GetHeadOfStack(callStack);
	//printf("�ָ���ַ:%d\n", returnIndex);
	PopCodeStack(callStack);
	(*pcIndex) = returnIndex;
}

extern void LoopCode(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
) {
	//ѭ����loopcounter��ֵС��0

	//��ջѭ��������ĺ�����ַ
	//printf("\n[warring]:ִ��ѭ�����,����ַΪ:%x %x %x %x\n",paramer1,paramer2,paramer3,paramer4);
	//��ָ��ָ��ָ��loopʱ��
	//ϵͳ�ȷ���loopcounter��ֵ���������ֵС��0��ֹͣ���У�����ָ��ָ������ָ��ĵ�ַ
	//����ϵͳ���Ȱѵ�ǰ��pc��(loop)λ����ջ��Ȼ��ȥ���ö�Ӧ��ѭ������
	int loopIndex = (*pcIndex);
	if (noaRegister[loopcounter]<=0)
	{
		(*pcIndex) = loopIndex + 5;
		//printf("[warring]:\nѭ������\n,ִ����һ�����:%d\n",(*pcIndex));
		
		return;
	}

	PushCodeStack(callStack, loopIndex);

	uint8 code[4];
	code[0] = paramer1;
	code[1] = paramer2;
	code[2] = paramer3;
	code[3] = paramer4;
	int64 funcHashCode = HashCode(code, 4, 0, 4096);
	FuncNode* func = GetFunc(&funcTable, funcHashCode);
	int64 funcIndex = func->pcIndex;
	(*pcIndex) = funcIndex;
	
}


void IFCode(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
) {
	//����ڴ��ַparamer1��ֵ==0��if��䲻��ȥ���ú���������ֱ��ȥִ����һ����䣬���ߣ�ȥִ�к�������
	if (ram->buffer[paramer1]==0)
	{
		//printf("\n[warring]:����������\n");
		(*pcIndex) = (*pcIndex) + 6;
		return;
	}
	//printf("\n[warring]:��������\n");
	int64 nextCodeIndex = (*pcIndex) + 6;
	PushCodeStack(callStack, nextCodeIndex);

	uint8 code[4];
	code[0] = paramer2;
	code[1] = paramer3;
	code[2] = paramer4;
	code[3] = paramer5;
	int64 funcHashCode = HashCode(code, 4, 0, 4096);
	FuncNode* func = GetFunc(&funcTable, funcHashCode);
	int64 funcIndex = func->pcIndex;
	(*pcIndex) = funcIndex;

	//���ú���

}

void ELSECode(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,
	uint8 paramer2,
	uint8 paramer3,
	uint8 paramer4,
	uint8 paramer5,
	uint8 paramer6,
	uint8 paramer7,
	uint8 paramer8,
	uint8 paramer9,
	uint8 paramer10,
	uint8 paramer11,
	uint8 paramer12,
	uint8 paramer13,
	uint8 paramer14,
	uint8 paramer15,
	uint8 paramer16,
	uint8 paramer17,
	uint8 paramer18,
	uint8 paramer19,
	uint8 paramer20,

	int64* pcIndex,
	NoaFile* file,
	CodeStack* callStack
) 
{
	
	if (ram->buffer[paramer1] != 0)
	{
		//����Ϊ�治ִ��
		//printf("\n[warring]:��������\n");
		(*pcIndex) = (*pcIndex) + 6;
		return;
	}
	//printf("\n[warring]:����������\n");
	int64 nextCodeIndex = (*pcIndex) + 6;
	PushCodeStack(callStack, nextCodeIndex);

	uint8 code[4];
	code[0] = paramer2;
	code[1] = paramer3;
	code[2] = paramer4;
	code[3] = paramer5;
	int64 funcHashCode = HashCode(code, 4, 0, 4096);
	FuncNode* func = GetFunc(&funcTable, funcHashCode);
	int64 funcIndex = func->pcIndex;
	(*pcIndex) = funcIndex;

	//���ú���
}

