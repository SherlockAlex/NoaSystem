#include "NoaRuntime.h"
#include "NoaMath.h"
#include <malloc.h>
#include <stdio.h>

void InitFuncTable(FuncTable* table) 
{
	printf("[warring]:��ʼ��������\n");
	table->count = 0;
	table->table = (FuncNode*)malloc(4096 * sizeof(FuncNode));
}


void InsertFuncNode(FuncTable * table,uint8  *code,int64 pcIndex)
{
	FuncNode funcNode;
	funcNode.funcHashCode[0] = code[0];
	funcNode.funcHashCode[1] = code[1];
	funcNode.funcHashCode[2] = code[2];
	funcNode.funcHashCode[3] = code[3];
	funcNode.pcIndex = pcIndex;
	int64 funcIndex = HashCode(code, 4, 0, 4096);
	table->table[funcIndex] = funcNode;
	table->count++;
	printf("[warring]���뺯���ɹ�:������:%x %x %x %x,hashCode:%d��PC:%d\n",code[0],code[1],code[2],code[3],funcIndex,pcIndex);
}

FuncNode* GetFunc(FuncTable * table,int64 hashCode)
{
	return &table->table[hashCode];
}