#include "NoaRuntime.h"
#include "NoaFunc.h"
#include <malloc.h>
#include "string.h"
#include <iostream>
#include <io.h>
#include "RAM.h"
#include "NoaCode.h"

int64 pc = 0x01;

int initInstructList(instructList* list)
{
	list->count = 0;
	list->instrct = (code*)malloc(MAXSIZEOFLIST*sizeof(code));
	return 0;
}

int insertInstruct(instructList* list, code instruct) {
	if (list->count>=MAXSIZEOFLIST) {
		return -1;
	}
	list->instrct[list->count] = instruct;
	list->count++;
	return 0;
}

code getInstruct(instructList* list, int64 adress) {
	//取指令
	for (int i = 0; i < list->count;i++) {
		if (list->instrct[i].adress == adress) {
			return list->instrct[i];
		}
	}
}

int getDataSize(const char * filePath) 
{
	FILE* file = fopen(filePath, "r");
	if (file==nullptr) {
		return 0;
	}
	int count = 0;

	//??

	int64 mess;
	while ((mess=fgetc(file))!=EOF)
	{
		count++;
	}

	fclose(file);
	return count;
}

NoaFile * loadFile(const char* filePath) {
	FILE* file = fopen(filePath,"r");
	if (fopen==nullptr) 
	{
		printf("加载文件失败\n");
		return nullptr;
	}
	int size = getDataSize(filePath);
	int64* data = (int64*)malloc(size * sizeof(int64));

	fread(data, sizeof(int64), size, file);

	fclose(file);

	bool isNoaFile = (data[0] == 0x4e && data[1] == 0x4f && data[2] == 0x41);

	if (!isNoaFile)
	{
		free(data);
		data = nullptr;
		free(data);
		return nullptr;
	}

	
	data = &(data[3]);

	int codeCount = 0;

	for (int i = 0; i < size; i++) {
		bool isCode = ((data[i] & (long)0xff00) == (long)0xff00);
		if (isCode)
		{
			codeCount++;
		}
	}


	//printf("init code size = %d\n", size);
	size = size-3;
	//printf("code size = %d\n",size);
	//printf("指令数量 = %d\n",codeCount);

	NoaFile* noaFile = InitNoaFile(data,size,codeCount);
	return noaFile;

}

int displayFile(NoaFile* file) {
	if (file==nullptr) {
		return 0;
	}
	for (int i = 0; i < file->length;i++) {
		printf("%c",file->data[i]);
	}
	return 0;
}

int initSystem(instructList* list) {
	

	initInstructList(list);

	code versionCode;
	versionCode.adress = ver;
	versionCode.func = version;
	versionCode.nextPC = 1;
	insertInstruct(list, versionCode);
	
	code printStrCode;
	printStrCode.adress = prts;
	printStrCode.func = printStr;
	printStrCode.nextPC = 1;
	insertInstruct(list, printStrCode);

	code movCode;
	movCode.adress = mov;
	movCode.func = moveToRegister;
	movCode.nextPC = 3;
	insertInstruct(list, movCode);

	code addCode;
	addCode.adress = add;
	addCode.func = addNumBToA;
	addCode.nextPC = 3;
	insertInstruct(list, addCode);

	code printCode;
	printCode.adress = prt;
	printCode.func = printRegister;
	printCode.nextPC = 3;
	insertInstruct(list, printCode);

	code subCode;
	subCode.adress = sub;
	subCode.func = ASubB;
	subCode.nextPC = 3;
	insertInstruct(list, subCode);
	
	code andCode;
	andCode.adress = AND;
	andCode.func = noaAnd;
	andCode.nextPC = 3;
	insertInstruct(list, andCode);

	code mstCode;
	mstCode.adress = mst;
	mstCode.func = heapToRAM;
	mstCode.nextPC = 1;
	insertInstruct(list, mstCode);
	
	code wtmCode;
	wtmCode.adress = wtm;
	wtmCode.func = WriteToRAM;
	wtmCode.nextPC = 3;
	insertInstruct(list, wtmCode);

	code orCode;
	orCode.adress = OR;
	orCode.func = noaOr;
	orCode.nextPC = 3;
	insertInstruct(list, orCode);

	code mulCode;
	mulCode.adress = mul;
	mulCode.func = multiply;
	mulCode.nextPC = 3;
	insertInstruct(list, mulCode);

	code divCode;
	divCode.adress = div;
	divCode.func = divide;
	divCode.nextPC = 3;
	insertInstruct(list, divCode);

	code callFuncCode;
	callFuncCode.adress = call;
	callFuncCode.func = callCode;
	callFuncCode.nextPC = 2;
	insertInstruct(list, callFuncCode);

	code recallFuncCode;
	recallFuncCode.adress = recall;
	recallFuncCode.func = recallCode;
	recallFuncCode.nextPC = 1;
	insertInstruct(list, recallFuncCode);


	return 0;
}

int run(NoaFile* file) {

	if (file==nullptr)
	{
		printf("运行Noa进程失败\n");
		return -1;
	}

	RAM * ram = InitRAM(2048);

	int dataStartPos = file->data[0];
	int dataLength = file->data[1];

	int length = file->length;
	instructList instructs;									//创建指令表
	initSystem(&instructs);

	int pcIndex = 0;
	int pramater1 = 0;										//函数使用的数据在ram中的地址
	int pramater2 = 0;
	pc = file->data[pcIndex];

	pramater1 = file->data[pcIndex + 1];					//参数1,可以是寄存器地址，ram地址
	pramater2 = file->data[pcIndex + 2];					//参数2,可以是寄存器地址，ram数据长度

	bool isRunning = true;
	int counter = 0;

	while (isRunning)
	{
		pc = file->data[pcIndex];
		pramater1 = file->data[pcIndex + 1];
		pramater2 = file->data[pcIndex + 2];					//获取下一条要执行的指令地址
		code currentCode = getInstruct(&instructs, pc);			//获得当前要执行的指令
		currentCode.func(ram, pramater1, pramater2,&pcIndex);			//执行指令
		pcIndex=pcIndex +currentCode.nextPC;					//pc -> pc + 1
		//只有当运行到结束命令时才会退出

		if (file->data[pcIndex] == quit) {
			pcIndex = 0;
			break;
		}
	}

	return 0;
}
