#include "NoaRuntime.h"
#include "malloc.h"
#include "stdio.h"

std::unordered_map<uint8, opFunc> operatorTable;

void InitOperator
(	uint8 adress,
	void (*func)(),
	OperatorMap* operatorMap
)
{
	Operator operatorNode;
	operatorNode.adress = adress;
	operatorNode.func = func;
	InsertOperator2Map(operatorMap, operatorNode);
}

static Operator ops[OPMAPSIZE];
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
	operatorTable[adress] = op.func;
}

Operator * GetOperator(const OperatorMap* map, uint8 adress) 
{
	return &(map->operatorMap[adress]);
}