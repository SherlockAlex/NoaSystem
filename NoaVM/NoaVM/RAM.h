#ifndef NOAVM_RAM_H
#define NOAVM_RAM_H

#include "type.h"

extern int64 noaRegister[7];//�Ĵ���
extern int64array noaHeap[1024];


//�����ڴ�
typedef struct RAM {
	int64 * buffer;//ram�ڴ�
	int bufferSize;
}RAM;

extern RAM * InitRAM(int ramSize);

#endif // !NOAVM_RAM_H
