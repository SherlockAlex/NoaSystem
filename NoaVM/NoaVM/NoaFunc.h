#ifndef NOAVM_NOAFUNC
#define NOAVM_NOAFUNC

#include "RAM.h"

extern void version(RAM* ram, int64 dpIndex, int64 dpLength, int* pcIndex);
extern void printStr(RAM* ram, int64 dpIndex, int64 dpLength, int* pcIndex);
extern void printRegister(RAM* ram, int64 registerIndex, int64 flags, int* pcIndex);

extern void moveToRegister(RAM* ram, int64 registerIndex, int64 data, int* pcIndex);
extern void addNumBToA(RAM* ram, int64 adress1, int64 adress2, int* pcIndex);
extern void ASubB(RAM* ram, int64 adress1, int64 adress2, int* pcIndex);
extern void noaAnd(RAM * ram,int64 adress1,int64 adress2, int* pcIndex);
extern void heapToRAM(RAM* ram, int64 registerIndex, int64 data, int* pcIndex);
extern void WriteToRAM(RAM* ram, int64 registerIndex, int64 data, int* pcIndex);
extern void noaOr(RAM * ram,int64 adress1,int64 adress2, int* pcIndex);
extern void multiply(RAM* ram, int64 adress1, int64 adress2, int* pcIndex);
extern void divide(RAM* ram, int64 adress1, int64 adress2, int* pcIndex);
extern void callCode(RAM* ram, int64 adress1, int64 adress2, int* pcIndex);

extern void recallCode(RAM* ram, int64 adress1, int64 adress2, int* pcIndex);

#endif // !NOAVM_NOAFUNC
