#include "NoaRuntime.h"
#include "malloc.h"
#include "stdio.h"

void InitOperator
(	uint8 adress,
	void (*func)(						//ִ�в���������תpc
		RAM* ram,						//�ڴ�ģ��
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
		CodeStack* callStack//pcָ���ַ)
		),
	OperatorMap* operatorMap
)
{
	Operator operatorNode;
	operatorNode.adress = adress;
	operatorNode.func = func;
	InsertOperator2Map(operatorMap, operatorNode);
}

void InitOperatorMap(OperatorMap* map, int length)
{
	map->count = 0;
	map->operatorMap = (Operator*)malloc(length * sizeof(Operator));
}

void InsertOperator2Map(OperatorMap* map, Operator op)
{
	/*map->operatorMap[map->count] = op;
	map->count++;*/
	printf("ָ���ʼ���ɹ�:%x\n",op.adress);
	uint8 adress = op.adress;
	map->operatorMap[adress] = op;
}

Operator * GetOperator(OperatorMap* map, uint8 adress) {
	/*for (int i = 0; i < map->count; i++)
	{
		if(map->operatorMap[i].adress==adress)
		{
			return &(map->operatorMap[i]);
		}
	}
	return nullptr;*/
	//printf("ָ���ַ:%x\n",adress);
	return &(map->operatorMap[adress]);
}