#ifndef NOAVM_RAM_H
#define NOAVM_RAM_H

#include "type.h"
#include <string>

#define STRINGPOOLSIZE 65536
#define INTPOOLSIZE 65536
#define FLOATPOOLSIZE 65536

#define RAMSIZE 256

extern int64 noaRegister[14];//寄存器

//运行内存
typedef struct RAM {
	int64* buffer;//ram内存
	int bufferSize;
}RAM;


//字符串常量池
typedef struct StringPool 
{
	char** buffer;
	int bufferSize;
}StringPool;

//整型常量池
typedef struct IntPool {
	int* buffer;
	int bufferSize;
}IntPool;

typedef struct FloatPool {
	float* buffer;
	int bufferSize;
}FloatPool;


//浮点数常量池

extern RAM * InitRAM(int ramSize);

extern StringPool * InitStringPool(int bufferSize);

extern IntPool* InitIntPool(int bufferSize);

extern FloatPool* InitFloatPool(int bufferSize);

extern char* GetStringFromPool(StringPool* pool,int64 hashCode);

extern int GetIntFromPool(IntPool *pool, int64 hashCode);

extern float GetStringFromPool(FloatPool* pool, int64 hashCode);

#endif // !NOAVM_RAM_H
