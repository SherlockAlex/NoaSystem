#include "NoaRuntime.h"
#include "malloc.h"
#include "stdio.h"

std::unordered_map<uint8, opFunc> OperatorTable;

void InitOperator
(	uint8 adress,
	void (*func)(						//执行操作，并跳转pc
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
		CodeStack* callStack//pc指令地址)
		),
	OperatorMap* operatorMap
)
{
	Operator operatorNode;
	operatorNode.adress = adress;
	operatorNode.func = func;
	InsertOperator2Map(operatorMap, operatorNode);
}

Operator ops[OPMAPSIZE];
void InitOperatorMap(OperatorMap* map, int length)
{
	map->count = 0;
	//map->operatorMap = (Operator*)malloc(length * sizeof(Operator));
	map->operatorMap = ops;
	if (map->operatorMap==nullptr)
	{
		printf("[error]:初始化指令表失败\n");
	}
}

void InsertOperator2Map(OperatorMap* map, Operator op)
{
	//printf("[warring]:指令初始化成功:%x\n",op.adress);
	uint8 adress = op.adress;
	map->operatorMap[adress] = op;
	OperatorTable[adress] = op.func;
}

Operator * GetOperator(OperatorMap* map, uint8 adress) 
{
	return &(map->operatorMap[adress]);
}