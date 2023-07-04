#include "NoaFunc.h"
#include "NoaCode.h"
#include "type.h"
#include "NoaMath.h"
#include <iostream>

using namespace std;

void PrintString(
	RAM* ram,						//内存模拟
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
	//打印字符串
	for (int64 i = noaRegister[2]; i < noaRegister[2] + noaRegister[3];i++) {
		printf("%c",ram->buffer[i]);
	}
	(*pcIndex) = (*pcIndex) + 1;
}


void PrintRegister(
	RAM* ram,						//内存模拟
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
	//打印寄存器里面的值
	switch (paramer2)
	{
		case 0x80:
			//打印字符
			printf("%c",noaRegister[paramer1]);
			break;
		case 0x81:
			//打印整形
			printf("%d", noaRegister[paramer1]);
			break;
		case 0x82:
			//打印浮点型
			//速度太慢
			value = *(float*)&noaRegister[paramer1];
			printf("%f", value);
			break;
		default:
			break;
	}
	(*pcIndex) = (*pcIndex) + 3;
}

void ScanCode(
	RAM* ram,						//内存模拟
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
	//读取数据到寄存器
	switch (paramer2)
	{
	case 0x80:
		//读取字符
		//scanf("%c", &noaRegister[paramer1]);
		cin >> valueChar;
		noaRegister[paramer1] = valueChar;
		break;
	case 0x81:
		//打印整形
		//scanf("%d", &noaRegister[paramer1]);
		cin >> valueInt;
		noaRegister[paramer1] = valueInt;
		break;
	case 0x82:
		//打印浮点型
		//速度太慢
		//scanf("%f", &value);
		cin >> valueFloat;
		noaRegister[paramer1] = *(int*)&valueFloat;
		//value = *(float*)&noaRegister[paramer1];
		break;
	default:
		cin >> noaRegister[paramer1];
		break;
	}
	//printf("读取数据完成,数据为:%c\n",noaRegister[paramer1]);
	(*pcIndex) = (*pcIndex) + 3;
}

void MoveToRegister(
	RAM* ram,						//内存模拟
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
	//printf("mov指令执行完成\n");
	//将ram中位置为dpIndex的数据放入寄存器中
	noaRegister[paramer1] = paramer2;
	(*pcIndex) = (*pcIndex) + 3;
	
}

void SaveRegister(
	RAM* ram,						//内存模拟
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
	RAM* ram,						//内存模拟
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
	//用于保存变量用的
	ram->buffer[paramer1] = noaRegister[paramer2];
	(*pcIndex) = (*pcIndex) + 3;
}

extern void ReadFromRAM(
	RAM* ram,						//内存模拟
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
	//内存地址占4位
	//从内存读取数据到寄存器中
	noaRegister[paramer1] = ram->buffer[paramer2];
	(*pcIndex) = (*pcIndex) + 3;
}

//规定函数的地址码和数据的地址码都为4B

void CallCode(
	RAM* ram,						//内存模拟
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
	//入栈
	int64 nextPos = ((*pcIndex) + 5);
	//printf("入栈地址:%d\n", nextPos);
	PushCodeStack(callStack, nextPos);
	
	//函数地址
	uint8 code[4];
	code[0] = paramer1;
	code[1] = paramer2;
	code[2] = paramer3;
	code[3] = paramer4;
	int64 funcHashCode = HashCode(code,4,0, FUNCTABLESIZE - 1);
	FuncNode* func = GetFunc(&funcTable,funcHashCode);
	//函数位置定位搜索算法
	int64 funcIndex = func->pcIndex;
	(*pcIndex) = funcIndex;
	
}
//
void ReturnCode(
	RAM* ram,						//内存模拟
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
	//恢复现场
	//recall
	int64 returnIndex = GetHeadOfStack(callStack);
	//printf("[warring]:恢复地址:%d\n", returnIndex);
	PopCodeStack(callStack);
	(*pcIndex) = returnIndex;
}

extern void LoopCode(
	RAM* ram,						//内存模拟
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
	//循环到loopcounter的值小于0
	int64 loopIndex = (*pcIndex);
	if (noaRegister[loopcounter]<=0)
	{
		(*pcIndex) = loopIndex + 5;
		//printf("[warring]:\n循环结束\n,执行下一条语句:%d\n",(*pcIndex));
		
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
	RAM* ram,						//内存模拟
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
	//如果内存地址paramer1的值==0，if语句不会去调用函数，而是直接去执行下一条语句，否者，去执行函数内容
	if (ram->buffer[paramer1]==0)
	{
		//printf("\n[warring]:条件不成立\n");
		(*pcIndex) = (*pcIndex) + 6;
		return;
	}
	//printf("\n[warring]:条件成立\n");
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

	//调用函数

}

void ELSECode(
	RAM* ram,						//内存模拟
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
		//条件为真不执行
		//printf("\n[warring]:条件成立\n");
		(*pcIndex) = (*pcIndex) + 6;
		return;
	}
	//printf("\n[warring]:条件不成立\n");
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

	//调用函数
}

void WriteString2Pool(
	RAM* ram,						//内存模拟
	uint8 paramer1,					//变量地址H
	uint8 paramer2,					//变量地址L
	uint8 paramer3,					//字符地址
	uint8 paramer4,					//字符
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
	//printf("[warring]:保存字符串到常量池中,字符index:%d,字符为:%c\n",charIndex, paramer4);
	if (stringPool->buffer[adress]==nullptr)
	{
		char stringValue[255];
		stringPool->buffer[adress] = stringValue;
	}
	stringPool->buffer[adress][charIndex] = paramer4;
	(*pcIndex) = (*pcIndex) + 5;
}

void ReadFromString(
	RAM* ram,						//内存模拟
	uint8 paramer1,					//数据地址H
	uint8 paramer2,					//数据地址L
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
	//printf("[warring]:读取字符串到内存中\n");
	uint8 code[2];
	code[0] = paramer1;
	code[1] = paramer2;

	int64 adress = HashCode(code,2,0, STRINGPOOLSIZE - 1);
	char* str = stringPool->buffer[adress];
	
	//printf("[warring]:读取到的字符串常量为:%s\n",str);

	//将字符串保存到一个特定的位置，即ram中
	for (int i=0;i<strlen(str);i++) 
	{
		ram->buffer[i] = str[i];
	}
	(*pcIndex) = (*pcIndex) + 3;

}

void WriteInt2Pool(
	RAM* ram,						//内存模拟
	uint8 paramer1,					//变量地址H
	uint8 paramer2,					//变量地址L
	uint8 paramer3,					//值H
	uint8 paramer4,					//值H
	uint8 paramer5,					//值H
	uint8 paramer6,					//值L
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
	//printf("[warring]:写入对象池整型数据:%d,十六进制为:%x %x %x %x\n",value,paramer3,paramer4,paramer5,paramer6);
	(*pcIndex) = (*pcIndex) + 7;
}

void RegisterInt2Pool(
	RAM* ram,						//内存模拟
	uint8 paramer1,					//地址H
	uint8 paramer2,					//地址L
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
	//printf("[warring]:写入对象池整型数据:%d,十六进制为:%x %x %x %x\n",value,paramer3,paramer4,paramer5,paramer6);
	(*pcIndex) = (*pcIndex) + 4;
}

void ReadIntFromPool(
	RAM* ram,						//内存模拟
	uint8 paramer1,					//变量地址H
	uint8 paramer2,					//变量地址L
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
	//printf("[warring]:内存整型数据:%d\n", value);

	//将字符串保存到一个特定的位置，即ram中
	ram->buffer[0] = value;
	(*pcIndex) = (*pcIndex) + 3;

}

void ReadIntToRegister(
	RAM* ram,						//内存模拟
	uint8 paramer1,					//数据地址H
	uint8 paramer2,					//数据地址L
	uint8 paramer3,					//寄存器地址L
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
	RAM* ram,						//内存模拟
	uint8 paramer1,					//地址H
	uint8 paramer2,					//地址L
	uint8 paramer3,					//寄存器地址
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
	//printf("[warring]:从寄存器读取数据成功\n");
	//printf("[warring]:写入对象池浮点型数据:%f,十六进制为:%x %x %x %x\n", value, paramer3, paramer4, paramer5, paramer6);
	(*pcIndex) = (*pcIndex) + 4;
}

void WriteFloat2Pool(
	RAM* ram,						//内存模拟
	uint8 paramer1,					//变量地址H
	uint8 paramer2,					//变量地址L
	uint8 paramer3,					//值
	uint8 paramer4,					//值
	uint8 paramer5,					//值
	uint8 paramer6,					//值
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
	//printf("[warring]:写入对象池浮点型数据:%f,十六进制为:%x %x %x %x\n", value, paramer3, paramer4, paramer5, paramer6);
	(*pcIndex) = (*pcIndex) + 7;
}

void ReadFloatFromPool(
	RAM* ram,						//内存模拟
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
	//printf("[warring]:内存浮点型数据:%f\n", value);
	//printf("[warring]:读取到的字符串常量为:%s\n",str);

	//将字符串保存到一个特定的位置，即ram中
	ram->buffer[0] = *(int *) &value;
	(*pcIndex) = (*pcIndex) + 3;
}

void ReadFloatToRegister(
	RAM* ram,						//内存模拟
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
	//printf("[warring]:浮点型数据:%f\n", value);
	//printf("[warring]:读取到的字符串常量为:%s\n",str);

	//将字符串保存到一个特定的位置，即ram中
	noaRegister[paramer3] = *(int64*)&value;
	(*pcIndex) = (*pcIndex) + 4;
}

void NoaOR(
	RAM* ram,						//内存模拟
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

//数据的四则运算
void SubCode(
	RAM* ram,						//内存模拟
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
	RAM* ram,						//内存模拟
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
		//printf("[warring]:运算结果:%d\n",noaRegister[paramer2]);
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
	RAM* ram,						//内存模拟
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
	RAM* ram,						//内存模拟
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


//逻辑运算
void CompareCode(
	RAM* ram,						//内存模拟
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
	//判断两个寄存器的值
	//0x00 ==
	//0x01 >
	//0x02 <
	//0x03 >=
	//0x04 <=
	//0x05 !=

	//逻辑
	//and
	//or
	//non

	//出现问题，寄存器中的值和浮点型整形不一样，比较结果不同
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
	RAM* ram,						//内存模拟
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

