#include "NoaRuntime.h"
#include "NoaFunc.h"
#include "string.h"
#include <iostream>
#include <stdio.h>
#include "RAM.h"
#include "NoaCode.h"
#include "NoaMath.h"

uint8 pc = 0x00;
FuncTable funcTable;

//PC
int64* PC;

//常量池区域
StringPool* stringPool;
IntPool* intPool;
FloatPool* floatPool;

//缓存区
RAM* ram;

//指令操作数区
Parameter parameter;

//函数调用栈
CodeStack callStack;

int64 GetDataSize(const char* filePath)
{
	FILE* file = fopen(filePath, "r");
	if (file == nullptr) {
		return 0;
	}

	fseek(file, 0, SEEK_END);
	int64 count = ftell(file);

	fclose(file);
	return count;
}

NoaFile * LoadFile(const char* filePath)
{
	FILE* file = fopen(filePath,"r");
	if (fopen==nullptr) 
	{
		printf("加载文件失败\n");
		return nullptr;
	}
	const int64 size = GetDataSize(filePath);
	static uint8* codes = (uint8*)malloc(size * sizeof(uint8));
	fread(codes, sizeof(int64), size, file);
	fclose(file);
	bool isNoaFile = (codes[0] == 0x4e && codes[1] == 0x4f && codes[2] == 0x41);
	if (!isNoaFile)
	{
		free(codes);
		return nullptr;
	}
	NoaFile* noaFile = InitNoaFile(codes,size);
	return noaFile;

}

int64 GetMainFuncIndex(FuncTable * table)
{
	//pc指向函数第一条指令的位置，fc一个字节标志，00 00 00 00表示地址
	int64 pcIndex = -1;
	uint8 code[4] = {_start,_start,_start,_start};
	int64 hashCode = HashCode(code,4,0, FUNCTABLESIZE-1);
	FuncNode * mainFunc = GetFunc(table, hashCode);
	if (mainFunc!=nullptr)
	{
		pcIndex = mainFunc->pcIndex;
	}
	return pcIndex;
}

int CreateOperator(OperatorMap * map)
{
	//寄存器操作
	InitOperator(mov,MoveToRegister,map);
	InitOperator(wtm, WriteToRAM, map);
	InitOperator(rfm, ReadFromRAM, map);
	InitOperator(SAV, SaveRegister, map);

	//io操作
	InitOperator(prt,PrintRegister,map);
	InitOperator(IN, ScanCode, map);
	InitOperator(prts,PrintString,map);
	
	//函数调用
	InitOperator(call, CallCode, map);
	InitOperator(_end, ReturnCode, map);
	InitOperator(loop,LoopCode,map);

	//if-else
	InitOperator(IF,IFCode,map);
	InitOperator(ELSE,ELSECode,map);

	//数据常量池
	InitOperator(STRING,WriteString2Pool,map);		//保存字符串变量到磁盘中
	InitOperator(STRREADER, ReadFromString, map);	//加载字符串到内存中

	InitOperator(INT, WriteInt2Pool, map);
	InitOperator(INTREADER,ReadIntFromPool,map);
	InitOperator(INTREGSTER,ReadIntToRegister,map);
	InitOperator(INTWRITE, RegisterInt2Pool, map);

	InitOperator(FLOAT,WriteFloat2Pool,map);
	InitOperator(FLOATREADER, ReadFloatFromPool, map);
	InitOperator(FLOATREGSTER,ReadFloatToRegister,map);
	InitOperator(FLOATWRITE, RegisterFloat2Pool, map);

	//四则运算
	InitOperator(sub, SubCode, map);
	InitOperator(add, AddCode, map);
	InitOperator(mul, MutiplyCode, map);
	InitOperator(div, DivideCode, map);
	InitOperator(MOD, ModCode, map);

	InitOperator(RAND, RandCode, map);

	//逻辑-条件运算
	InitOperator(CMP, CompareCode, map);
	InitOperator(NON, NonCode, map);

	return 0;
}

void CreateFuncTable(NoaFile * file,FuncTable * table) {
	uint8 code[4];
	for (uint32 i = 4; i < file->length;i++)
	{
		if (file->data[i-4]==fun)
		{
			code[0] = file->data[i - 3];
			code[1] = file->data[i - 2];
			code[2] = file->data[i - 1];
			code[3] = file->data[i];
			InsertFuncNode(table, code, (i + 1));
		}
	}
}

void InitConstantPool() {
	//初始化常量池
	stringPool = InitStringPool(STRINGPOOLSIZE);
	intPool = InitIntPool(INTPOOLSIZE);
	floatPool = InitFloatPool(FLOATPOOLSIZE);
}

int Run(NoaFile* file) {

	if (file==nullptr)
	{
		printf("error:运行Noa进程失败\n");
		return -1;
	}
	//运行内存：(1024*1024)Byte
	ram = InitRAM(RAMSIZE);
	
	//初始化指令表
	OperatorMap opMap;
	
	InitOperatorMap(&opMap, OPMAPSIZE);

	CreateOperator(&opMap);
	
	//初始化函数栈
	InitCodeStack(&callStack,CALLINDEXSIZE);
	int64 pcIndex = 0;
	PC = &pcIndex;
	//初始化函数表
	InitFuncTable(&funcTable);
	CreateFuncTable(file,&funcTable);
	
	//初始化常量池
	InitConstantPool();

	//获取主函数地址
	pcIndex = GetMainFuncIndex(&funcTable);
	if (pcIndex<0)
	{
		printf("[error]:无法找到程序入口地址: .Main:\n");
		free(ram);
		free(file->data);
		free(file);
		free(stringPool);
		free(intPool);
		free(floatPool);
		return -1;
	}

	const uint8* fileData = file->data;
	const OperatorMap* opMapAdress = &opMap;
	pc = fileData[pcIndex];
	
	uint8* parameters = parameter.paramer;
	clock_t startTime = clock();
	while (1)
	{
		//运行速度太慢
		pc = fileData[pcIndex];
		if (pc == quit) 
		{
			pcIndex = 0;
			break;
		}
		memcpy(parameters, &fileData[(pcIndex + 1)], 20 * sizeof(uint8));
		const Operator * op = GetOperator(opMapAdress,pc);//效率慢
		op->func();

	}

	std::cout << std::endl << "[warring]:运行时间:" << double(clock() - startTime) / CLOCKS_PER_SEC << std::endl;

	//释放计算机资源
	free(ram);
	free(file->data);
	free(file);
	free(stringPool);
	free(intPool);
	free(floatPool);
	return 0;
}
