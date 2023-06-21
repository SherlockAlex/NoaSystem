#ifndef NOAVM_NOARUNTIME_H
#define NOAVM_NOARUNTIME_H
#define MAXSIZEOFLIST 100

#include "NoaFile.h"
#include "RAM.h"


typedef struct code {
	//指令
	int64 adress;												//指令地址
	void (*func)(RAM * ram,int64 dpIndex,int64 dpLength,int* pcIndex);		//指令
	int nextPC;
}code;

typedef struct instructList {
	//指令集
	code* instrct;
	int count;
} instructList;

extern int64 pc;

extern int initInstructList(instructList * list);
extern int insertInstruct(instructList * list,code instruct);
extern code getInstruct(instructList * list,int64 adress);

extern NoaFile * loadFile(const char *filePath);//返回的是一个函数指针
extern int displayFile(NoaFile * file);
extern int run(NoaFile * file);

#endif // !NOAVM_NOARUNTIME_H
