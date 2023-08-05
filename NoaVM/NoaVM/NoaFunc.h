#ifndef NOAVM_NOAFUNC
#define NOAVM_NOAFUNC

#include "NoaFile.h"
#include "NoaRuntime.h"
#include "RAM.h"

//PC
extern int64* PC;

//操作数
extern Parameter parameter;

//缓存
extern RAM* ram;

//函数调用栈
extern CodeStack callStack;

extern void PrintString();

extern void PrintRegister();

extern void ScanCode();

extern void MoveToRegister();

extern void SaveRegister();


extern void WriteToRAM();

extern void ReadFromRAM();

extern void WriteString2Pool();

extern void ReadFromString();

extern void RegisterInt2Pool();

extern void WriteInt2Pool();

extern void ReadIntFromPool();

extern void ReadIntToRegister();

extern void RegisterFloat2Pool();

extern void WriteFloat2Pool();

extern void ReadFloatFromPool();

extern void ReadFloatToRegister();

extern void CallCode();

extern void ReturnCode();

extern void IFCode();

extern void ELSECode();

extern void LoopCode();

extern void SubCode();

extern void AddCode();

extern void MutiplyCode();

extern void DivideCode();

extern void ModCode();

extern void RandCode();

//逻辑运算
extern void CompareCode();

extern void NonCode();

#endif // !NOAVM_NOAFUNC