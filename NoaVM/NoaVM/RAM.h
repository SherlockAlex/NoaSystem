#ifndef NOAVM_RAM_H
#define NOAVM_RAM_H

#include "type.h"

extern int64 noaRegister[7];//寄存器
extern int64array noaHeap[1024];


//运行内存
typedef struct RAM {
	int64 * buffer;//ram内存
	int bufferSize;
}RAM;

extern RAM * InitRAM(int ramSize);

#endif // !NOAVM_RAM_H
