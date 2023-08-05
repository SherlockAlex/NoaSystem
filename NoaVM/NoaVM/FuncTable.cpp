#include "NoaRuntime.h"
#include "NoaMath.h"
#include <malloc.h>
#include <stdio.h>
static FuncNode funcBuffer[FUNCTABLESIZE];

static std::unordered_map<uint32,int64> funcHashTable;

void InitFuncTable(FuncTable* table)
{
	//printf("[warring]:初始化函数表\n");
	table->count = 0;
	table->table = funcBuffer;

	if (table->table == nullptr)
	{
		printf("[error]:初始化指令表失败\n");
	}
}


void InsertFuncNode(FuncTable * table,uint8  *code,int64 pcIndex)
{
	FuncNode funcNode;
	funcNode.funcHashCode[0] = code[0];
	funcNode.funcHashCode[1] = code[1];
	funcNode.funcHashCode[2] = code[2];
	funcNode.funcHashCode[3] = code[3];
	funcNode.pcIndex = pcIndex;
	int64 funcIndex = HashCode(code, 4, 0, FUNCTABLESIZE-1);
	table->table[funcIndex] = funcNode;
	table->count++;
	uint32 byteToInt = ByteToInt(code);
	funcHashTable[byteToInt] = funcIndex;

	//保存哈希值到表中
	//funcHashTable[code[0]][code[1]][code[2]][code[3]] = funcIndex;

	printf("[warring]:插入函数成功:函数名:%x %x %x %x,hashCode:%d，PC:%d,byteToInt:%d\n",code[0],code[1],code[2],code[3],funcIndex,pcIndex,byteToInt);
}

FuncNode* GetFunc(const FuncTable * table,const int64 hashCode)
{
	return &table->table[hashCode];
}

FuncNode* GetFunc(const FuncTable* table, const uint8* code) 
{
	int64 funcIndex = funcHashTable[ByteToInt(code)];
	return &table->table[funcIndex];
}