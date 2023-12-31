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

//字符串常量池
extern StringPool* stringPool;

//整形常量池
extern IntPool* intPool;

//单精度浮点数常量池
extern FloatPool* floatPool;


typedef struct FuncNode {
	//方法表对象，会在虚拟机加载noa文件时候，变量表，索引是函数的哈希值
	uint8 funcHashCode[4];				//方法的哈希值
	int64 pcIndex;						//方法noa文件中的位置
}FuncNode;

typedef struct FuncTable {
	//方法表
	FuncNode* table;
	int count;
}FuncTable;

typedef struct CodeStack {
	//栈,存放函数头的地址或者函数断点地址,当end指令执行是，表示一个函数运行完，出栈
	int64* codeIndex;
	int64 top;
}CodeStack;

typedef struct Parameter {
	uint8 paramer[20];
}Parameter;

typedef struct Operator {
	//操作码
	//一个操作码一般前面第一个字节表示操作地址，
	//第二个字节表示参数的地址
	uint8 adress;						//指令地址
	void (*func)();								//指令
}Operator;

typedef void(*opFunc)();//定义别名才能放在vector中

extern std::unordered_map<uint8, opFunc> operatorTable;

extern std::unordered_map<uint32, int64> funcHashTable;

typedef struct OperatorMap {
	//指令链表
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

extern NoaFile * LoadFile(const char *filePath);//返回的是一个函数指针
extern int Run(NoaFile * file);

extern void InitCodeStack(CodeStack* stack,int length);
extern void PushCodeStack(CodeStack* stack,const int64 code);	//入栈
extern int64 PopCodeStack(CodeStack * stack);			//出栈并返回
extern int64 GetHeadOfStack(CodeStack * stack);			//返回栈顶元素

extern FuncTable funcTable;

extern void InitFuncTable(FuncTable* table);
extern void InsertFuncNode(FuncTable* table, uint8* code, int64 pcIndex);
extern FuncNode* GetFunc(const FuncTable* table, const int64 hashCode);
extern FuncNode* GetFunc(const FuncTable* table, const uint8 * code);
#endif // !NOAVM_NOARUNTIME_H
