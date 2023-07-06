#ifndef NOAVM_PROCESS_H

#include "NoaRuntime.h"
#include "NoaFunc.h"
#include "string.h"
#include <iostream>
#include <stdio.h>
#include "RAM.h"
#include "NoaCode.h"
#include "NoaMath.h"

class Process
{

public:
	uint8 pc = 0x00;
	FuncTable funcTable;

	//³£Á¿³ØÇøÓò
	StringPool* stringPool;
	IntPool* intPool;
	FloatPool* floatPool;

public:
	Process();
	~Process();

public:
	int Run(NoaFile* file);
};
#endif // !NOAVM_PROCESS_H



