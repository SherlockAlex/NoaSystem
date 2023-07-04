#include "NoaFunc.h"
#include "NoaCode.h"
#include "type.h"
#include "NoaMath.h"
#include <iostream>

using namespace std;

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
	//��ӡ�ַ���
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
	float value = 0;
	//��ӡ�Ĵ��������ֵ
	switch (paramer2)
	{
		case 0x80:
			//��ӡ�ַ�
			printf("%c",noaRegister[paramer1]);
			break;
		case 0x81:
			//��ӡ����
			printf("%d", noaRegister[paramer1]);
			break;
		case 0x82:
			//��ӡ������
			//�ٶ�̫��
			value = *(float*)&noaRegister[paramer1];
			printf("%f", value);
			break;
		default:
			break;
	}
	(*pcIndex) = (*pcIndex) + 3;
}

void ScanCode(
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
	int   valueInt = 0;
	float valueFloat = 0;
	char  valueChar;
	//��ȡ���ݵ��Ĵ���
	switch (paramer2)
	{
	case 0x80:
		//��ȡ�ַ�
		//scanf("%c", &noaRegister[paramer1]);
		cin >> valueChar;
		noaRegister[paramer1] = valueChar;
		break;
	case 0x81:
		//��ӡ����
		//scanf("%d", &noaRegister[paramer1]);
		cin >> valueInt;
		noaRegister[paramer1] = valueInt;
		break;
	case 0x82:
		//��ӡ������
		//�ٶ�̫��
		//scanf("%f", &value);
		cin >> valueFloat;
		noaRegister[paramer1] = *(int*)&valueFloat;
		//value = *(float*)&noaRegister[paramer1];
		break;
	default:
		cin >> noaRegister[paramer1];
		break;
	}
	//printf("��ȡ�������,����Ϊ:%c\n",noaRegister[paramer1]);
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

void SaveRegister(
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
	noaRegister[paramer1] = noaRegister[paramer2];
	(*pcIndex) = (*pcIndex) + 3;
}


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
	ram->buffer[paramer1] = noaRegister[paramer2];
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
	noaRegister[paramer1] = ram->buffer[paramer2];
	(*pcIndex) = (*pcIndex) + 3;
}

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
	int64 funcHashCode = HashCode(code,4,0, FUNCTABLESIZE - 1);
	FuncNode* func = GetFunc(&funcTable,funcHashCode);
	//����λ�ö�λ�����㷨
	int64 funcIndex = func->pcIndex;
	(*pcIndex) = funcIndex;
	
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
	//printf("[warring]:�ָ���ַ:%d\n", returnIndex);
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
	int64 loopIndex = (*pcIndex);
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
	int64 funcHashCode = HashCode(code, 4, 0, FUNCTABLESIZE - 1);
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
	int64 funcHashCode = HashCode(code, 4, 0, FUNCTABLESIZE-1);
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
	int64 funcHashCode = HashCode(code, 4, 0, FUNCTABLESIZE-1);
	FuncNode* func = GetFunc(&funcTable, funcHashCode);
	int64 funcIndex = func->pcIndex;
	(*pcIndex) = funcIndex;

	//���ú���
}

void WriteString2Pool(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,					//������ַH
	uint8 paramer2,					//������ַL
	uint8 paramer3,					//�ַ���ַ
	uint8 paramer4,					//�ַ�
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

	uint8 code[2];
	code[0] = paramer1;
	code[1] = paramer2;

	
	int64 adress = HashCode(code,2,0,STRINGPOOLSIZE-1);
	int charIndex = (int)paramer3;
	//printf("[warring]:�����ַ�������������,�ַ�index:%d,�ַ�Ϊ:%c\n",charIndex, paramer4);
	if (stringPool->buffer[adress]==nullptr)
	{
		char stringValue[255];
		stringPool->buffer[adress] = stringValue;
	}
	stringPool->buffer[adress][charIndex] = paramer4;
	(*pcIndex) = (*pcIndex) + 5;
}

void ReadFromString(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,					//���ݵ�ַH
	uint8 paramer2,					//���ݵ�ַL
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
	//printf("[warring]:��ȡ�ַ������ڴ���\n");
	uint8 code[2];
	code[0] = paramer1;
	code[1] = paramer2;

	int64 adress = HashCode(code,2,0, STRINGPOOLSIZE - 1);
	char* str = stringPool->buffer[adress];
	
	//printf("[warring]:��ȡ�����ַ�������Ϊ:%s\n",str);

	//���ַ������浽һ���ض���λ�ã���ram��
	for (int i=0;i<strlen(str);i++) 
	{
		ram->buffer[i] = str[i];
	}
	(*pcIndex) = (*pcIndex) + 3;

}

void WriteInt2Pool(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,					//������ַH
	uint8 paramer2,					//������ַL
	uint8 paramer3,					//ֵH
	uint8 paramer4,					//ֵH
	uint8 paramer5,					//ֵH
	uint8 paramer6,					//ֵL
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
	uint8 code[2];
	code[0] = paramer1;
	code[1] = paramer2;

	int64 adress = HashCode(code, 2, 0, INTPOOLSIZE-1);

	int value = 0;
	//value = (int)((((int)paramer3) << 24)+(((int)paramer4) << 16) + (((int)paramer5) << 8) + ((int)paramer6));
	value = (int)(((paramer3 & 0xff) << 24) | ((paramer4 & 0xff) << 16) | ((paramer5 & 0xff) << 8) | (paramer6 & 0xff));
	intPool->buffer[adress] = value;
	//printf("[warring]:д��������������:%d,ʮ������Ϊ:%x %x %x %x\n",value,paramer3,paramer4,paramer5,paramer6);
	(*pcIndex) = (*pcIndex) + 7;
}

void RegisterInt2Pool(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,					//��ַH
	uint8 paramer2,					//��ַL
	uint8 paramer3,					//register
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
	uint8 code[2];
	code[0] = paramer1;
	code[1] = paramer2;

	int64 adress = HashCode(code, 2, 0, INTPOOLSIZE - 1);

	//int value = 0;
	////value = (int)((((int)paramer3) << 24)+(((int)paramer4) << 16) + (((int)paramer5) << 8) + ((int)paramer6));
	//value = (int)(((paramer3 & 0xff) << 24) | ((paramer4 & 0xff) << 16) | ((paramer5 & 0xff) << 8) | (paramer6 & 0xff));
	intPool->buffer[adress] = noaRegister[paramer3];
	//printf("[warring]:д��������������:%d,ʮ������Ϊ:%x %x %x %x\n",value,paramer3,paramer4,paramer5,paramer6);
	(*pcIndex) = (*pcIndex) + 4;
}

void ReadIntFromPool(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,					//������ַH
	uint8 paramer2,					//������ַL
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

	uint8 code[2];
	code[0] = paramer1;
	code[1] = paramer2;

	int64 adress = HashCode(code, 2, 0, INTPOOLSIZE - 1);
	int value = intPool->buffer[adress];
	//printf("[warring]:�ڴ���������:%d\n", value);

	//���ַ������浽һ���ض���λ�ã���ram��
	ram->buffer[0] = value;
	(*pcIndex) = (*pcIndex) + 3;

}

void ReadIntToRegister(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,					//���ݵ�ַH
	uint8 paramer2,					//���ݵ�ַL
	uint8 paramer3,					//�Ĵ�����ַL
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
	uint8 code[2];
	code[0] = paramer1;
	code[1] = paramer2;

	int64 adress = HashCode(code, 2, 0, INTPOOLSIZE - 1);
	int value = intPool->buffer[adress];
	noaRegister[paramer3] = value;
	(*pcIndex) = (*pcIndex) + 4;
}

void RegisterFloat2Pool(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,					//��ַH
	uint8 paramer2,					//��ַL
	uint8 paramer3,					//�Ĵ�����ַ
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
	uint8 code[2];
	code[0] = paramer1;
	code[1] = paramer2;

	int64 adress = HashCode(code, 2, 0, FLOATPOOLSIZE - 1);

	int64 valueInt = 0;
	valueInt = noaRegister[paramer3];

	float value = 0;
	value = *(float*)&valueInt;

	floatPool->buffer[adress] = value;
	//printf("[warring]:�ӼĴ�����ȡ���ݳɹ�\n");
	//printf("[warring]:д�����ظ���������:%f,ʮ������Ϊ:%x %x %x %x\n", value, paramer3, paramer4, paramer5, paramer6);
	(*pcIndex) = (*pcIndex) + 4;
}

void WriteFloat2Pool(
	RAM* ram,						//�ڴ�ģ��
	uint8 paramer1,					//������ַH
	uint8 paramer2,					//������ַL
	uint8 paramer3,					//ֵ
	uint8 paramer4,					//ֵ
	uint8 paramer5,					//ֵ
	uint8 paramer6,					//ֵ
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
	uint8 code[2];
	code[0] = paramer1;
	code[1] = paramer2;

	int64 adress = HashCode(code, 2, 0, FLOATPOOLSIZE - 1);

	int valueInt = 0;
	valueInt = (int)(((paramer3 & 0xff) << 24) | ((paramer4 & 0xff) << 16) | ((paramer5 & 0xff) << 8) | (paramer6 & 0xff));

	float value = 0;
	value = *(float*)&valueInt;

	floatPool->buffer[adress] = value;
	//printf("[warring]:д�����ظ���������:%f,ʮ������Ϊ:%x %x %x %x\n", value, paramer3, paramer4, paramer5, paramer6);
	(*pcIndex) = (*pcIndex) + 7;
}

void ReadFloatFromPool(
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
	uint8 code[2];
	code[0] = paramer1;
	code[1] = paramer2;

	int64 adress = HashCode(code, 2, 0, FLOATPOOLSIZE - 1);
	float value = floatPool->buffer[adress];
	//printf("[warring]:�ڴ渡��������:%f\n", value);
	//printf("[warring]:��ȡ�����ַ�������Ϊ:%s\n",str);

	//���ַ������浽һ���ض���λ�ã���ram��
	ram->buffer[0] = *(int *) &value;
	(*pcIndex) = (*pcIndex) + 3;
}

void ReadFloatToRegister(
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
	uint8 code[2];
	code[0] = paramer1;
	code[1] = paramer2;

	int64 adress = HashCode(code, 2, 0, FLOATPOOLSIZE - 1);
	float value = floatPool->buffer[adress];
	//printf("[warring]:����������:%f\n", value);
	//printf("[warring]:��ȡ�����ַ�������Ϊ:%s\n",str);

	//���ַ������浽һ���ض���λ�ã���ram��
	noaRegister[paramer3] = *(int64*)&value;
	(*pcIndex) = (*pcIndex) + 4;
}

void NoaOR(
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
	noaRegister[paramer1] = (noaRegister[paramer1] | noaRegister[paramer2]);
}

//���ݵ���������
void SubCode(
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

	float value1 = 0;
	float value2 = 0;

	switch (paramer1)
	{
		
		case 0x80:
			noaRegister[paramer2] -= noaRegister[paramer3];
			break;
		case 0x81:
			noaRegister[paramer2] -= noaRegister[paramer3];
			break;
		case 0x82:
			value1 = *(float*)&noaRegister[paramer2];
			value2 = *(float*)&noaRegister[paramer3];
			value1 -= value2;
			noaRegister[paramer2] = *(int64 *)&value1;
			break;
		default:
			noaRegister[paramer1] -= noaRegister[paramer2];
	}
	
	(*pcIndex) = ((*pcIndex) + 4);
}

void AddCode(
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
	switch (paramer1)
	{
	case 0x80:
		noaRegister[paramer2] += noaRegister[paramer3];
		break;
	case 0x81:
		noaRegister[paramer2] += noaRegister[paramer3];
		//printf("[warring]:������:%d\n",noaRegister[paramer2]);
		break;
	case 0x82:
		float value1 = *(float*)&noaRegister[paramer2];
		float value2 = *(float*)&noaRegister[paramer3];
		value1 += value2;
		noaRegister[paramer2] = *(int64*)&value1;
		break;
	}

	(*pcIndex) = ((*pcIndex) + 4);
}

void MutiplyCode(
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
	switch (paramer1)
	{
	case 0x80:
		noaRegister[paramer2] *= noaRegister[paramer3];
		break;
	case 0x81:
		noaRegister[paramer2] *= noaRegister[paramer3];
		break;
	case 0x82:
		float value1 = *(float*)&noaRegister[paramer2];
		float value2 = *(float*)&noaRegister[paramer3];
		value1 *= value2;
		noaRegister[paramer2] = *(int64*)&value1;
		break;
	}

	(*pcIndex) = ((*pcIndex) + 4);
}

void DivideCode(
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
	switch (paramer1)
	{
	case 0x80:
		noaRegister[paramer2] /= noaRegister[paramer3];
		break;
	case 0x81:
		noaRegister[paramer2] /= noaRegister[paramer3];
		break;
	case 0x82:
		float value1 = *(float*)&noaRegister[paramer2];
		float value2 = *(float*)&noaRegister[paramer3];
		value1 /= value2;
		noaRegister[paramer2] = *(int64*)&value1;
		break;
	}

	(*pcIndex) = ((*pcIndex) + 4);
}


//�߼�����
void CompareCode(
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
	//�ж������Ĵ�����ֵ
	//0x00 ==
	//0x01 >
	//0x02 <
	//0x03 >=
	//0x04 <=
	//0x05 !=

	//�߼�
	//and
	//or
	//non

	//�������⣬�Ĵ����е�ֵ�͸��������β�һ�����ȽϽ����ͬ
	if (paramer1==0x82) 
	{
		float value1 = *(float*)&noaRegister[paramer3];
		float value2 = *(float*)&noaRegister[paramer4];
		switch (paramer2)
		{
		case 0x00:
			noaRegister[qx] = (value1 == value2) ? 1 : 0;
			break;
		case 0x01:
			noaRegister[qx] = (value1 > value2) ? 1 : 0;
			//printf("qx = %lld 2=%lld 3=%lld\n",noaRegister[qx],noaRegister[paramer2],noaRegister[paramer3]);
			//printf("qx = %d 2=%d 3=%d\n", noaRegister[qx], noaRegister[paramer2], noaRegister[paramer3]);
			break;
		case 0x02:
			noaRegister[qx] = (value1 < value2) ? 1 : 0;
			break;
		case 0x03:
			noaRegister[qx] = (value1 >= value2) ? 1 : 0;
			break;
		case 0x04:
			noaRegister[qx] = (value1 <= value2) ? 1 : 0;
			break;
		case 0x05:
			noaRegister[qx] = (value1 != value2) ? 1 : 0;
			break;

		case AND:
			noaRegister[qx] = (value1 && value2) ? 1 : 0;
			break;
		case OR:
			noaRegister[qx] = (value1 || value2) ? 1 : 0;
			break;

		}
	}
	else if(paramer1==0x81||paramer1==0x80)
	{
		int value1 = noaRegister[paramer3];
		int value2 = noaRegister[paramer4];
		switch (paramer2)
		{
		case 0x00:
			noaRegister[qx] = (value1 == value2) ? 1 : 0;
			break;
		case 0x01:
			noaRegister[qx] = (value1 > value2) ? 1 : 0;
			//printf("qx = %lld 2=%lld 3=%lld\n",noaRegister[qx],noaRegister[paramer2],noaRegister[paramer3]);
			//printf("qx = %d 2=%d 3=%d\n", noaRegister[qx], noaRegister[paramer2], noaRegister[paramer3]);
			break;
		case 0x02:
			noaRegister[qx] = (value1 < value2) ? 1 : 0;
			break;
		case 0x03:
			noaRegister[qx] = (value1 >= value2) ? 1 : 0;
			break;
		case 0x04:
			noaRegister[qx] = (value1 <= value2) ? 1 : 0;
			break;
		case 0x05:
			noaRegister[qx] = (value1 != value2) ? 1 : 0;
			break;
		case AND:
			noaRegister[qx] = (value1 && value2) ? 1 : 0;
			break;
		case OR:
			noaRegister[qx] = (value1 || value2) ? 1 : 0;
			break;

		}
	}
	else {
		int64 value1 = noaRegister[paramer3];
		int64 value2 = noaRegister[paramer4];
		switch (paramer2)
		{
		case 0x00:
			noaRegister[qx] = (value1 == value2) ? 1 : 0;
			break;
		case 0x01:
			noaRegister[qx] = (value1 > value2) ? 1 : 0;
			//printf("qx = %lld 2=%lld 3=%lld\n",noaRegister[qx],noaRegister[paramer2],noaRegister[paramer3]);
			//printf("qx = %d 2=%d 3=%d\n", noaRegister[qx], noaRegister[paramer2], noaRegister[paramer3]);
			break;
		case 0x02:
			noaRegister[qx] = (value1 < value2) ? 1 : 0;
			break;
		case 0x03:
			noaRegister[qx] = (value1 >= value2) ? 1 : 0;
			break;
		case 0x04:
			noaRegister[qx] = (value1 <= value2) ? 1 : 0;
			break;
		case 0x05:
			noaRegister[qx] = (value1 != value2) ? 1 : 0;
			break;

		case AND:
			noaRegister[qx] = (value1 && value2) ? 1 : 0;
			break;
		case OR:
			noaRegister[qx] = (value1 || value2) ? 1 : 0;
			break;

		}
	}
	(*pcIndex) = ((*pcIndex) + 5);
}

void NonCode(
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
	noaRegister[qx] = ~(noaRegister[qx]);
	(*pcIndex) = ((*pcIndex) + 1);
}

