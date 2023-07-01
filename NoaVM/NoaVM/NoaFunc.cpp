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
	//使用add前，必须先使用mov指令将数字放到寄存器内部
	noaRegister[paramer1] = AddB(noaRegister[paramer1],noaRegister[paramer2]);
	(*pcIndex) = (*pcIndex) + 3;
}

void Sub(
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
	noaRegister[paramer1] -= noaRegister[paramer2];
	(*pcIndex) = ((*pcIndex) + 3);
}

//
//void ASubB(RAM* ram, int64 adresss1, int64 adresss2, int* pcIndex)
//{
//	//减法操作
//	noaRegister[adresss1] -= noaRegister[adresss2];
//}
//
//void noaAnd(RAM* ram, int64 adress1, int64 adress2, int* pcIndex)
//{
//	//与运算
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
	ram->buffer[paramer1] = paramer2;
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
	int64 funcHashCode = HashCode(code,4,0,4096);
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
	int64 funcHashCode = HashCode(code, 4, 0, 4096);
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
	int64 funcHashCode = HashCode(code, 4, 0, 4096);
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
	int64 funcHashCode = HashCode(code, 4, 0, 4096);
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

	
	int64 adress = HashCode(code,2,0,65535);
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

	int64 adress = HashCode(code,2,0,65535);
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

	int64 adress = HashCode(code, 2, 0, 65535);

	int value = 0;
	value = (int)(((paramer3 & 0xff) << 24) | ((paramer4 & 0xff) << 16) | ((paramer5 & 0xff) << 8) | (paramer6 & 0xff));
	intPool->buffer[adress] = value;
	//printf("[warring]:写入对象池整型数据:%d,十六进制为:%x %x %x %x\n",value,paramer3,paramer4,paramer5,paramer6);
	(*pcIndex) = (*pcIndex) + 7;
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

	int64 adress = HashCode(code, 2, 0, 65535);
	int value = intPool->buffer[adress];
	//printf("[warring]:内存整型数据:%d\n", value);
	//printf("[warring]:读取到的字符串常量为:%s\n",str);

	//将字符串保存到一个特定的位置，即ram中
	ram->buffer[0] = value;
	(*pcIndex) = (*pcIndex) + 3;

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

	int64 adress = HashCode(code, 2, 0, 65535);

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

	int64 adress = HashCode(code, 2, 0, 65535);
	float value = floatPool->buffer[adress];
	//printf("[warring]:内存浮点型数据:%f\n", value);
	//printf("[warring]:读取到的字符串常量为:%s\n",str);

	//将字符串保存到一个特定的位置，即ram中
	ram->buffer[0] = *(int *) &value;
	(*pcIndex) = (*pcIndex) + 3;
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
