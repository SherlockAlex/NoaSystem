#include "NoaFunc.h"
#include "NoaCode.h"
#include "type.h"
#include "NoaMath.h"
#include <iostream>

using namespace std;

void printChar(const int value);
void printInt(const int value);
void printFloat(const int value);
typedef void(*const ioType)(const int);
std::unordered_map<int64, ioType> print = { 
	{0x80,printChar},
	{0x81,printInt},
	{0x82,printFloat},
};


void SubChar(const uint8 addr1, const uint8 addr2);
void SubInt(const uint8 addr1, const uint8 addr2);
void SubFloat(const uint8 addr1, const uint8 addr2);
typedef void(*const accType)(const uint8, const uint8);
std::unordered_map<int64, accType> subtraction = {
	{0x80,SubChar},
	{0x81,SubInt},
	{0x82,SubFloat},
};

void PrintString() {
	//��ӡ�ַ���
	for (int64 i = noaRegister[2]; i < noaRegister[2] + noaRegister[3];i++) {
		printf("%c",ram->buffer[i]);
	}
	(*PC) = (*PC) + 1;
}



// �����ӡ����
void printChar(const int value) {
	const char charValue = value;
	printf("%c",charValue);
}

void printInt(const int value) {
	printf("%d", value);
}

void printFloat(const int value) {
	int i = value;
	float floatValue = *(float*)&i;
	printf("%f", floatValue);
}

void PrintRegister()
{
	const int registerValue = noaRegister[parameter.paramer[0]];
	//��ӡ�Ĵ��������ֵ
	print[parameter.paramer[1]](registerValue);
	(*PC) = (*PC) + 3;
}

void ScanCode() {
	int   valueInt = 0;
	float valueFloat = 0;
	char  valueChar;
	//��ȡ���ݵ��Ĵ���
	switch (parameter.paramer[1])
	{
	case 0x80:
		cin >> valueChar;
		noaRegister[parameter.paramer[0]] = valueChar;
		break;
	case 0x81:
		cin >> valueInt;
		noaRegister[parameter.paramer[0]] = valueInt;
		break;
	case 0x82:
		cin >> valueFloat;
		noaRegister[parameter.paramer[0]] = *(int*)&valueFloat;
		break;
	default:
		cin >> noaRegister[parameter.paramer[0]];
		break;
	}
	(*PC) = (*PC) + 3;
}

void MoveToRegister()
{
	noaRegister[parameter.paramer[0]] = parameter.paramer[1];
	(*PC) = (*PC) + 3;
}

void SaveRegister() {
	noaRegister[parameter.paramer[0]] = noaRegister[parameter.paramer[1]];
	(*PC) = (*PC) + 3;
}


void WriteToRAM()
{
	//���ڱ�������õ�
	ram->buffer[parameter.paramer[0]] = noaRegister[parameter.paramer[1]];
	(*PC) = (*PC) + 3;
}

void ReadFromRAM()
{
	//�ڴ��ַռ4λ
	//���ڴ��ȡ���ݵ��Ĵ�����
	noaRegister[parameter.paramer[0]] = ram->buffer[parameter.paramer[1]];
	(*PC) = (*PC) + 3;
}

//�涨�����ĵ�ַ������ݵĵ�ַ�붼Ϊ4B

void CallCode() {
	//��ջ
	int64 nextPos = ((*PC) + 5);
	//printf("��ջ��ַ:%d\n", nextPos);
	PushCodeStack(&callStack, nextPos);
	
	//������ַ
	uint8 code[4];
	code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];
	code[2] = parameter.paramer[2];
	code[3] = parameter.paramer[3];
	const FuncNode* func = GetFunc(&funcTable, code);
	const int64 funcIndex = func->pcIndex;
	(*PC) = funcIndex;
	
}
//
void ReturnCode() 
{
	//�ָ��ֳ�
	//recall
	const int64 returnIndex = PopCodeStack(&callStack);
	//printf("[warring]:�ָ���ַ:%d\n", returnIndex);
	(*PC) = returnIndex;
}

extern void LoopCode() {
	const int64 loopIndex = (*PC);
	if (noaRegister[loopcounter]<=0)
	{
		(*PC) = loopIndex + 5;
		return;
	}

	PushCodeStack(&callStack, loopIndex);
	//int64 funcIndex = 0;
	const uint8 code[4] = {
		parameter.paramer[0],
		parameter.paramer[1],
		parameter.paramer[2],
		parameter.paramer[3],
	};
	/*code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];
	code[2] = parameter.paramer[2];
	code[3] = parameter.paramer[3];*/

	const FuncNode* func = GetFunc(&funcTable, code);
	const int64 funcIndex = func->pcIndex;
	(*PC) = funcIndex;
}


void IFCode() {
	//����ڴ��ַparamer1��ֵ==0��if��䲻��ȥ���ú���������ֱ��ȥִ����һ����䣬���ߣ�ȥִ�к�������
	if (ram->buffer[parameter.paramer[0]]==0)
	{
		//printf("\n[warring]:����������\n");
		(*PC) = (*PC) + 6;
		return;
	}
	const int64 nextCodeIndex = (*PC) + 6;
	PushCodeStack(&callStack, nextCodeIndex);
	uint8 code[4];
	code[0] = parameter.paramer[1];
	code[1] = parameter.paramer[2];
	code[2] = parameter.paramer[3];
	code[3] = parameter.paramer[4];

	const FuncNode* func = GetFunc(&funcTable, code);
	const int64 funcIndex = func->pcIndex;
	//printf("[warring]:��һ�������:%x %x %x %x,pc:%d\n", code[0], code[1], code[2], code[3], func->pcIndex);
	(*PC) = funcIndex;
}

void ELSECode() 
{
	
	if (ram->buffer[parameter.paramer[0]] != 0)
	{
		(*PC) = (*PC) + 6;
		return;
	}
	const int64 nextCodeIndex = (*PC) + 6;
	PushCodeStack(&callStack, nextCodeIndex);
	uint8 code[4];
	code[0] = parameter.paramer[1];
	code[1] = parameter.paramer[2];
	code[2] = parameter.paramer[3];
	code[3] = parameter.paramer[4];
	const FuncNode* func = GetFunc(&funcTable, code);
	const int64 funcIndex = func->pcIndex;
	(*PC) = funcIndex;
}

void WriteString2Pool() 
{

	uint8 code[2];
	code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];

	
	const int64 adress = HashCode(code,2,0,STRINGPOOLSIZE-1);
	const int charIndex = (int)parameter.paramer[2];
	if (stringPool->buffer[adress]==nullptr)
	{
		char stringValue[255];
		stringPool->buffer[adress] = stringValue;
	}
	stringPool->buffer[adress][charIndex] = parameter.paramer[3];
	(*PC) = (*PC) + 5;
}

void ReadFromString() 
{
	//printf("[warring]:��ȡ�ַ������ڴ���\n");
	uint8 code[2];
	code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];
	const int64 adress = HashCode(code,2,0, STRINGPOOLSIZE - 1);
	const char* str = stringPool->buffer[adress];
	
	for (int i=0;i<strlen(str);i++) 
	{
		ram->buffer[i] = str[i];
	}
	(*PC) = (*PC) + 3;

}

void WriteInt2Pool() 
{
	uint8 code[2];
	code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];

	const int64 adress = HashCode(code, 2, 0, INTPOOLSIZE-1);
	const int value = (int)(((parameter.paramer[2] & 0xff) << 24) | ((parameter.paramer[3] & 0xff) << 16) | ((parameter.paramer[4] & 0xff) << 8) | (parameter.paramer[5] & 0xff));
	intPool->buffer[adress] = value;
	(*PC) = (*PC) + 7;
}

void RegisterInt2Pool() {
	uint8 code[2];
	code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];
	const int64 adress = HashCode(code, 2, 0, INTPOOLSIZE - 1);
	intPool->buffer[adress] = noaRegister[parameter.paramer[2]];
	(*PC) = (*PC) + 4;
}

void ReadIntFromPool() {

	uint8 code[2];
	code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];

	const int64 adress = HashCode(code, 2, 0, INTPOOLSIZE - 1);
	const int value = intPool->buffer[adress];
	ram->buffer[0] = value;
	(*PC) = (*PC) + 3;

}

void ReadIntToRegister() {
	uint8 code[2];
	code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];

	//�Ż�
	const int64 adress = HashCode(code, 2, 0, INTPOOLSIZE - 1);
	const int value = intPool->buffer[adress];
	noaRegister[parameter.paramer[2]] = value;
	(*PC) = (*PC) + 4;
}

void RegisterFloat2Pool() {
	uint8 code[2];
	code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];

	const int64 adress = HashCode(code, 2, 0, FLOATPOOLSIZE - 1);

	const int64 valueInt = noaRegister[parameter.paramer[2]];

	const float value = *(float*)&valueInt;

	floatPool->buffer[adress] = value;
	//printf("[warring]:�ӼĴ�����ȡ���ݳɹ�\n");
	//printf("[warring]:д�����ظ���������:%f,ʮ������Ϊ:%x %x %x %x\n", value, paramer3, paramer4, paramer5, paramer6);
	(*PC) = (*PC) + 4;
}

void WriteFloat2Pool() 
{
	uint8 code[2];
	code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];

	const int64 adress = HashCode(code, 2, 0, FLOATPOOLSIZE - 1);

	const int valueInt = (int)(
		((parameter.paramer[2] & 0xff) << 24) 
		| ((parameter.paramer[3] & 0xff) << 16) 
		| ((parameter.paramer[4] & 0xff) << 8)
		| (parameter.paramer[5] & 0xff));

	const float value = *(float*)&valueInt;
	

	floatPool->buffer[adress] = value;
	//printf("[warring]:д�����ظ���������:%f,ʮ������Ϊ:%x %x %x %x\n", value, paramer3, paramer4, paramer5, paramer6);
	(*PC) = (*PC) + 7;
}

void ReadFloatFromPool() 
{
	uint8 code[2];
	code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];

	const int64 adress = HashCode(code, 2, 0, FLOATPOOLSIZE - 1);
	const float value = floatPool->buffer[adress];

	//���ַ������浽һ���ض���λ�ã���ram��
	ram->buffer[0] = *(int *) &value;
	(*PC) = (*PC) + 3;
}

void ReadFloatToRegister() {
	uint8 code[2];
	code[0] = parameter.paramer[0];
	code[1] = parameter.paramer[1];

	const int64 adress = HashCode(code, 2, 0, FLOATPOOLSIZE - 1);
	const float value = floatPool->buffer[adress];

	//���ַ������浽һ���ض���λ�ã���ram��
	noaRegister[parameter.paramer[2]] = *(int64*)&value;
	(*PC) = (*PC) + 4;
}

void NoaOR() {
	noaRegister[parameter.paramer[0]] = (noaRegister[parameter.paramer[0]] 
		| noaRegister[parameter.paramer[1]]);
}

void SubChar(const uint8 addr1, const uint8 addr2)
{
	noaRegister[addr1] -= noaRegister[addr2];
}

void SubInt(const uint8 addr1, const uint8 addr2)
{
	noaRegister[addr1] -= noaRegister[addr2];
}

void SubFloat(const uint8 addr1, const uint8 addr2) {
	float value1 = *(float*)&noaRegister[addr1];
	float value2 = *(float*)&noaRegister[addr2];
	value1 -= value2;
	noaRegister[parameter.paramer[1]] = *(int64*)&value1;
}

//���ݵ���������
void SubCode() {
	const uint8 addr = parameter.paramer[0];
	const uint8 reg1 = parameter.paramer[1];
	const uint8 reg2 = parameter.paramer[2];
	subtraction[addr](reg1, reg2);
	(*PC) = ((*PC) + 4);
}

void AddCode() {
	switch (parameter.paramer[0])
	{
	case 0x80:
		noaRegister[parameter.paramer[1]] += noaRegister[parameter.paramer[2]];
		break;
	case 0x81:
		noaRegister[parameter.paramer[1]] += noaRegister[parameter.paramer[2]];
		//printf("[warring]:������:%d\n",noaRegister[paramer2]);
		break;
	case 0x82:
		float value1 = *(float*)&noaRegister[parameter.paramer[1]];
		float value2 = *(float*)&noaRegister[parameter.paramer[2]];
		value1 += value2;
		noaRegister[parameter.paramer[1]] = *(int64*)&value1;
		break;
	}

	(*PC) = ((*PC) + 4);
}

void MutiplyCode() {
	switch (parameter.paramer[0])
	{
	case 0x80:
		noaRegister[parameter.paramer[1]] *= noaRegister[parameter.paramer[2]];
		break;
	case 0x81:
		noaRegister[parameter.paramer[1]] *= noaRegister[parameter.paramer[2]];
		break;
	case 0x82:
		float value1 = *(float*)&noaRegister[parameter.paramer[1]];
		float value2 = *(float*)&noaRegister[parameter.paramer[2]];
		value1 *= value2;
		noaRegister[parameter.paramer[1]] = *(int64*)&value1;
		break;
	}

	(*PC) = ((*PC) + 4);
}

void DivideCode() {
	switch (parameter.paramer[0])
	{
	case 0x80:
		noaRegister[parameter.paramer[1]] /= noaRegister[parameter.paramer[2]];
		break;
	case 0x81:
		noaRegister[parameter.paramer[1]] /= noaRegister[parameter.paramer[2]];
		break;
	case 0x82:
		float value1 = *(float*)&noaRegister[parameter.paramer[1]];
		float value2 = *(float*)&noaRegister[parameter.paramer[2]];
		value1 /= value2;
		noaRegister[parameter.paramer[1]] = *(int64*)&value1;
		break;
	}

	(*PC) = ((*PC) + 4);
}


void ModCode() {
	switch (parameter.paramer[0])
	{
	case 0x80:
		noaRegister[parameter.paramer[1]] %= noaRegister[parameter.paramer[2]];
		break;
	case 0x81:
		noaRegister[parameter.paramer[1]] %= noaRegister[parameter.paramer[2]];
		break;
	case 0x82:
		int value1 = *(float*)&noaRegister[parameter.paramer[1]];
		int value2 = *(float*)&noaRegister[parameter.paramer[2]];
		value1 %= value2;
		noaRegister[parameter.paramer[1]] = *(int64*)&value1;
		break;
	}

	(*PC) = ((*PC) + 4);
}

void RandCode() {
	//�����������ax
	srand((unsigned)time(nullptr));
	noaRegister[ax] = rand();
	(*PC) = (*PC) + 1;
}

//�߼�����
void CompareCode() {
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
	if (parameter.paramer[0] == 0x82)
	{
		float value1 = *(float*)&noaRegister[parameter.paramer[2]];
		float value2 = *(float*)&noaRegister[parameter.paramer[3]];
		switch (parameter.paramer[1])
		{
		case 0x00:
			noaRegister[qx] = (value1 == value2) ? 1 : 0;
			break;
		case 0x01:
			noaRegister[qx] = (value1 > value2) ? 1 : 0;
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
	else if(parameter.paramer[0] == 0x81 || parameter.paramer[0] == 0x80)
	{
		int value1 = noaRegister[parameter.paramer[2]];
		int value2 = noaRegister[parameter.paramer[3]];
		switch (parameter.paramer[1])
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
		int64 value1 = noaRegister[parameter.paramer[2]];
		int64 value2 = noaRegister[parameter.paramer[3]];
		switch (parameter.paramer[1])
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
	(*PC) = ((*PC) + 5);
}

void NonCode() {
	noaRegister[qx] = ~(noaRegister[qx]);
	(*PC) = ((*PC) + 1);
}

