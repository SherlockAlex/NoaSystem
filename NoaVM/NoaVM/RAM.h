#ifndef NOAVM_RAM_H
#define NOAVM_RAM_H

#include "type.h"
#include <string>

extern uint8 noaRegister[7];//寄存器


//运行内存
typedef struct RAM {
	uint8* buffer;//ram内存
	int bufferSize;
}RAM;


//字符串常量池
typedef struct StringPool {
	std::string* buffer;
	int bufferSize;
}StringPool;

//整型常量池
typedef struct IntPool {
	int* buffer;
	int bufferSize;
};

//浮点数常量池

extern RAM * InitRAM(int ramSize);





#endif // !NOAVM_RAM_H
