#ifndef NOAVM_NOARUNTIME_H
#define NOAVM_NOARUNTIME_H
#define MAXSIZEOFLIST 100

#include "NoaFile.h"
#include "string.h"
#include "RAM.h"

#define OPMAPSIZE 256
#define CALLINDEXSIZE 1024
#define FUNCTABLESIZE 4096

//�ַ���������
extern StringPool* stringPool;

//���γ�����
extern IntPool* intPool;

//�����ȸ�����������
extern FloatPool* floatPool;


typedef struct FuncNode {
	//��������󣬻������������noa�ļ�ʱ�򣬱����������Ǻ����Ĺ�ϣֵ
	uint8 funcHashCode[4];				//�����Ĺ�ϣֵ
	int64 pcIndex;						//����noa�ļ��е�λ��
}FuncNode;

typedef struct FuncTable {
	//������
	FuncNode* table;
	int count;
}FuncTable;

typedef struct CodeStack {
	//ջ,��ź���ͷ�ĵ�ַ���ߺ����ϵ��ַ,��endָ��ִ���ǣ���ʾһ�����������꣬��ջ
	int64* codeIndex;
	int64 top;
}CodeStack;

typedef struct Operator {
	//������
	//һ��������һ��ǰ���һ���ֽڱ�ʾ������ַ��
	//�ڶ����ֽڱ�ʾ�����ĵ�ַ
	uint8 adress;						//ָ���ַ
	void (*func)(
		RAM * ram,						//�ڴ�ģ��
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
		NoaFile * file,
		CodeStack * callStack
		//pcָ���ַ
		);								//ָ��
}Operator;

typedef struct OperatorMap {
	//ָ������
	Operator* operatorMap;
	int count;
}OperatorMap;


extern void InitOperator(
	uint8 adress,
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
	OperatorMap * operatorMap
);



extern void InitOperatorMap(OperatorMap* map,int length);

extern void InsertOperator2Map(OperatorMap * map,Operator op);

extern Operator* GetOperator(OperatorMap * map,uint8 adress);

extern NoaFile * LoadFile(const char *filePath);//���ص���һ������ָ��
extern int Run(NoaFile * file);

extern void InitCodeStack(CodeStack* stack,int length);
extern void PushCodeStack(CodeStack* stack, int64 code);	//��ջ
extern int64 PopCodeStack(CodeStack * stack);			//��ջ������
extern int64 GetHeadOfStack(CodeStack * stack);			//����ջ��Ԫ��

extern FuncTable funcTable;

extern void InitFuncTable(FuncTable* table);
extern void InsertFuncNode(FuncTable* table, uint8* code, int64 pcIndex);
extern FuncNode* GetFunc(FuncTable* table, int64 hashCode);
#endif // !NOAVM_NOARUNTIME_H
