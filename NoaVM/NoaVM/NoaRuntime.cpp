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

//常量池区域
StringPool* stringPool;
IntPool* intPool;
FloatPool* floatPool;

int64 GetDataSize(const char * filePath) 
{
	FILE* file = fopen(filePath, "r");
	if (file==nullptr) {
		return 0;
	}
	int64 count = 0;

	int64 mess;
	while ((mess=fgetc(file))!=EOF)
	{
		count++;
	}

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
	int64 size = GetDataSize(filePath);
	uint8* codes = (uint8*)malloc(size * sizeof(uint8));
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
	int64 hashCode = HashCode(code,4,0, FUNCTABLESIZE);
	FuncNode * mainFunc = GetFunc(table, hashCode);
	if (mainFunc!=nullptr)
	{
		pcIndex = mainFunc->pcIndex;
	}
	return pcIndex;
}

int CreateOperator(OperatorMap * map)
{
	InitOperator(mov,MoveToRegister,map);
	InitOperator(prt,PrintRegister,map);
	InitOperator(prts,PrintString,map);
	InitOperator(wtm, WriteToRAM, map);
	InitOperator(add, AddByte, map);
	InitOperator(rfm, ReadFromRAM, map);
	InitOperator(call, CallCode, map);
	InitOperator(_end, ReturnCode, map);
	InitOperator(loop,LoopCode,map);
	InitOperator(sub,Sub,map);
	InitOperator(IF,IFCode,map);
	InitOperator(ELSE,ELSECode,map);
	InitOperator(STRING,WriteString2Pool,map);		//保存字符串变量到磁盘中
	InitOperator(STRREADER, ReadFromString, map);	//加载字符串到内存中
	InitOperator(INT, WriteInt2Pool, map);
	InitOperator(INTREADER,ReadIntFromPool,map);
	InitOperator(FLOAT,WriteFloat2Pool,map);
	InitOperator(FLOATREADER, ReadFloatFromPool, map);
	InitOperator(OR,NoaOR,map);
	return 0;
}

void CreateFuncTable(NoaFile * file,FuncTable * table) {
	uint8 code[4];
	for (int i = 4; i < file->length;i++)
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
	RAM * ram = InitRAM(RAMSIZE);
	
	//初始化指令表
	OperatorMap opMap;
	CodeStack callStack;
	InitOperatorMap(&opMap, OPMAPSIZE);

	CreateOperator(&opMap);
	
	//初始化函数栈
	InitCodeStack(&callStack,CALLINDEXSIZE);
	int64 pcIndex = 0;
	
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


	pc = file->data[pcIndex];
	//printf("初始的指令为:%x\n",pc);
	uint8 pramater1 = 0;
	uint8 pramater2 = 0;
	uint8 pramater3 = 0;
	uint8 pramater4 = 0;
	uint8 pramater5 = 0;
	uint8 pramater6 = 0;
	uint8 pramater7 = 0;
	uint8 pramater8 = 0;
	uint8 pramater9 = 0;
	uint8 pramater10 = 0;
	uint8 pramater11 = 0;
	uint8 pramater12 = 0;
	uint8 pramater13 = 0;
	uint8 pramater14 = 0;
	uint8 pramater15 = 0;
	uint8 pramater16 = 0;
	uint8 pramater17 = 0;
	uint8 pramater18 = 0;
	uint8 pramater19 = 0;
	uint8 pramater20 = 0;

	bool isRunning = true;
	//int counter = 0;

	//printf("\n[warring]:开始执行Noa文件\n");
	//clock_t startTime = clock();
	while (isRunning)
	{
		//运行速度太慢
		pc = file->data[pcIndex];
		if (pc == quit) 
		{
			//printf("msg:程序执行完成\n");
			pcIndex = 0;
			break;
		}
		pramater1 = file->data[pcIndex + 1];
		pramater2 = file->data[pcIndex + 2];
		pramater3 = file->data[pcIndex + 3];
		pramater4 = file->data[pcIndex + 4];
		pramater5 = file->data[pcIndex + 5];
		pramater6 = file->data[pcIndex + 6];
		pramater7 = file->data[pcIndex + 7];
		pramater8 = file->data[pcIndex + 8];
		pramater9 = file->data[pcIndex + 9];
		pramater10 = file->data[pcIndex + 10];
		pramater11 = file->data[pcIndex + 11];
		pramater12 = file->data[pcIndex + 12];
		pramater13 = file->data[pcIndex + 13];
		pramater14 = file->data[pcIndex + 14];
		pramater15 = file->data[pcIndex + 15];
		pramater16 = file->data[pcIndex + 16];
		pramater17 = file->data[pcIndex + 17];
		pramater18 = file->data[pcIndex + 18];
		pramater19 = file->data[pcIndex + 19];
		pramater20 = file->data[pcIndex + 20];

		Operator * op = GetOperator(&opMap,pc);//效率慢
		op->func(ram,
			pramater1,pramater2,pramater3,pramater4,
			pramater5,pramater6,pramater7,pramater8,
			pramater9,pramater10,pramater11,pramater12,
			pramater13,pramater14,pramater15,pramater16,
			pramater17,pramater18,pramater19,pramater20,
			&pcIndex,file,&callStack);

	}

	//std::cout << std::endl << "[warring]:运行时间:" << double(clock() - startTime) / CLOCKS_PER_SEC << std::endl;

	//释放计算机资源
	free(ram);
	free(file->data);
	free(file);
	free(stringPool);
	free(intPool);
	free(floatPool);
	//printf("释放资源完成\n");
	return 0;
}
