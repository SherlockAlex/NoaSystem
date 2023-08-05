#ifndef NOAVM_NOARUNTIME_H
#define NOAVM_NOARUNTIME_H
#define MAXSIZEOFLIST 100

#include "NoaFile.h"
#include "string.h"
#include "RAM.h"
#include <map>
#include <unordered_map>

#define OPMAPSIZE 256
#define CALLINDEXSIZE 65535
#define FUNCTABLESIZE 65535

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

typedef struct Parameter {
	uint8 paramer[20];
}Parameter;

typedef struct Operator {
	//������
	//һ��������һ��ǰ���һ���ֽڱ�ʾ������ַ��
	//�ڶ����ֽڱ�ʾ�����ĵ�ַ
	uint8 adress;						//ָ���ַ
	void (*func)();								//ָ��
}Operator;

typedef void(*opFunc)();//����������ܷ���vector��

extern std::unordered_map<uint8, opFunc> operatorTable;

extern std::unordered_map<uint32, int64> funcHashTable;

typedef struct OperatorMap {
	//ָ������
	Operator* operatorMap;
	int count;
}OperatorMap;

extern void InitOperator(
	uint8 adress,
	void (*func)(),
	OperatorMap * operatorMap
);



extern void InitOperatorMap(OperatorMap* map,int length);

extern void InsertOperator2Map(OperatorMap * map,Operator op);

extern Operator* GetOperator(const OperatorMap * map,uint8 adress);

extern NoaFile * LoadFile(const char *filePath);//���ص���һ������ָ��
extern int Run(NoaFile * file);

extern void InitCodeStack(CodeStack* stack,int length);
extern void PushCodeStack(CodeStack* stack,const int64 code);	//��ջ
extern int64 PopCodeStack(CodeStack * stack);			//��ջ������
extern int64 GetHeadOfStack(CodeStack * stack);			//����ջ��Ԫ��

extern FuncTable funcTable;

extern void InitFuncTable(FuncTable* table);
extern void InsertFuncNode(FuncTable* table, uint8* code, int64 pcIndex);
extern FuncNode* GetFunc(const FuncTable* table, const int64 hashCode);
extern FuncNode* GetFunc(const FuncTable* table, const uint8 * code);
#endif // !NOAVM_NOARUNTIME_H
