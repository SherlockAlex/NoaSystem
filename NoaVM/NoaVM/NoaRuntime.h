#ifndef NOAVM_NOARUNTIME_H
#define NOAVM_NOARUNTIME_H
#define MAXSIZEOFLIST 100

#include "NoaFile.h"
#include "RAM.h"


typedef struct code {
	//ָ��
	int64 adress;												//ָ���ַ
	void (*func)(RAM * ram,int64 dpIndex,int64 dpLength,int* pcIndex);		//ָ��
	int nextPC;
}code;

typedef struct instructList {
	//ָ�
	code* instrct;
	int count;
} instructList;

extern int64 pc;

extern int initInstructList(instructList * list);
extern int insertInstruct(instructList * list,code instruct);
extern code getInstruct(instructList * list,int64 adress);

extern NoaFile * loadFile(const char *filePath);//���ص���һ������ָ��
extern int displayFile(NoaFile * file);
extern int run(NoaFile * file);

#endif // !NOAVM_NOARUNTIME_H
