#include "RAM.h"
#include "malloc.h"
#include "type.h"

int64 noaRegister[14] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00};

static int64 ramBuffer[RAMSIZE];

RAM * InitRAM(int ramSize) {
	RAM* ram = (RAM*)malloc(sizeof(RAM));
	ram->bufferSize = ramSize;
	ram->buffer = ramBuffer;
	//ram->buffer = (int64*)malloc(ramSize * sizeof(int64));
	return ram;
}

static char* stringBuffer[STRINGPOOLSIZE];					//静态分配常量池大小
StringPool* InitStringPool(int bufferSize) {
	StringPool* stringPool = (StringPool*)malloc(sizeof(StringPool));
	stringPool->bufferSize = bufferSize;
	stringPool->buffer = stringBuffer;
	//stringPool->buffer = (char**)malloc(bufferSize * sizeof(char*));
	return stringPool;
}

static int intBuffer[INTPOOLSIZE];
IntPool* InitIntPool(int bufferSize) {
	IntPool* intPool = (IntPool*)malloc(sizeof(IntPool));
	intPool->bufferSize = bufferSize;
	intPool->buffer = intBuffer;
	//intPool->buffer = (int*)malloc(bufferSize * sizeof(int));
	return intPool;
}

static float floatBuffer[FLOATPOOLSIZE];
FloatPool* InitFloatPool(int bufferSize) {
	FloatPool* pool = (FloatPool*)malloc(sizeof(FloatPool));
	pool->bufferSize = bufferSize;
	pool->buffer = floatBuffer;
	//pool->buffer = (float*)malloc(bufferSize * sizeof(float));
	return pool;
}

char* GetStringFromPool(StringPool* pool, int64 hashCode) 
{
	return pool->buffer[hashCode];
}

int GetIntFromPool(IntPool* pool, int64 hashCode) 
{
	return pool->buffer[hashCode];
}

float GetStringFromPool(FloatPool* pool, int64 hashCode) 
{
	return pool->buffer[hashCode];
}