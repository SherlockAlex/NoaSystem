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
	//打印寄存器里面的值
	switch (paramer2)
	{
		case 0x80:
			//打印字符
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
	//int adress = paramer1 * (16777216) + paramer2 * (65535) + paramer3 * (256) + paramer4;
	//ram->buffer[adress] = paramer5;
	//(*pcIndex) = (*pcIndex) + 6;
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
	//printf("\n[warring]:调用函数,语句地址为:%x %x %x %x，pc : %d\n", paramer1, paramer2, paramer3, paramer4,(*pcIndex));

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
	//printf("恢复地址:%d\n", returnIndex);
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

	//入栈循环出来后的函数地址
	//printf("\n[warring]:执行循环语句,语句地址为:%x %x %x %x\n",paramer1,paramer2,paramer3,paramer4);
	//当指令指针指到loop时候
	//系统先访问loopcounter的值，如果他的值小于0，停止运行，并将指针指向下条指令的地址
	//否则，系统会先把当前的pc的(loop)位置入栈，然后去调用对应的循环函数
	int loopIndex = (*pcIndex);
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

