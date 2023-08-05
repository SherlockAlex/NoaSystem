#include "NoaRuntime.h"
#include "NoaFunc.h"
#include "string.h"
#include <iostream>
#include <stdio.h>
#include "RAM.h"
#include "NoaCode.h"
#include "NoaMath.h"

uint8 pc = 0x00;
FuncTable funcTable;

//PC
int64* PC;

//����������
StringPool* stringPool;
IntPool* intPool;
FloatPool* floatPool;

//������
RAM* ram;

//ָ���������
Parameter parameter;

//��������ջ
CodeStack callStack;

int64 GetDataSize(const char* filePath)
{
	FILE* file = fopen(filePath, "r");
	if (file == nullptr) {
		return 0;
	}

	fseek(file, 0, SEEK_END);
	int64 count = ftell(file);

	fclose(file);
	return count;
}

NoaFile * LoadFile(const char* filePath)
{
	FILE* file = fopen(filePath,"r");
	if (fopen==nullptr) 
	{
		printf("�����ļ�ʧ��\n");
		return nullptr;
	}
	const int64 size = GetDataSize(filePath);
	static uint8* codes = (uint8*)malloc(size * sizeof(uint8));
	fread(codes, sizeof(int64), size, file);
	fclose(file);
	bool isNoaFile = (codes[0] == 0x4e && codes[1] == 0x4f && codes[2] == 0x41);
	if (!isNoaFile)
	{
		free(codes);
		return nullptr;
	}
	NoaFile* noaFile = InitNoaFile(codes,size);
	return noaFile;

}

int64 GetMainFuncIndex(FuncTable * table)
{
	//pcָ������һ��ָ���λ�ã�fcһ���ֽڱ�־��00 00 00 00��ʾ��ַ
	int64 pcIndex = -1;
	uint8 code[4] = {_start,_start,_start,_start};
	int64 hashCode = HashCode(code,4,0, FUNCTABLESIZE-1);
	FuncNode * mainFunc = GetFunc(table, hashCode);
	if (mainFunc!=nullptr)
	{
		pcIndex = mainFunc->pcIndex;
	}
	return pcIndex;
}

int CreateOperator(OperatorMap * map)
{
	//�Ĵ�������
	InitOperator(mov,MoveToRegister,map);
	InitOperator(wtm, WriteToRAM, map);
	InitOperator(rfm, ReadFromRAM, map);
	InitOperator(SAV, SaveRegister, map);

	//io����
	InitOperator(prt,PrintRegister,map);
	InitOperator(IN, ScanCode, map);
	InitOperator(prts,PrintString,map);
	
	//��������
	InitOperator(call, CallCode, map);
	InitOperator(_end, ReturnCode, map);
	InitOperator(loop,LoopCode,map);

	//if-else
	InitOperator(IF,IFCode,map);
	InitOperator(ELSE,ELSECode,map);

	//���ݳ�����
	InitOperator(STRING,WriteString2Pool,map);		//�����ַ���������������
	InitOperator(STRREADER, ReadFromString, map);	//�����ַ������ڴ���

	InitOperator(INT, WriteInt2Pool, map);
	InitOperator(INTREADER,ReadIntFromPool,map);
	InitOperator(INTREGSTER,ReadIntToRegister,map);
	InitOperator(INTWRITE, RegisterInt2Pool, map);

	InitOperator(FLOAT,WriteFloat2Pool,map);
	InitOperator(FLOATREADER, ReadFloatFromPool, map);
	InitOperator(FLOATREGSTER,ReadFloatToRegister,map);
	InitOperator(FLOATWRITE, RegisterFloat2Pool, map);

	//��������
	InitOperator(sub, SubCode, map);
	InitOperator(add, AddCode, map);
	InitOperator(mul, MutiplyCode, map);
	InitOperator(div, DivideCode, map);
	InitOperator(MOD, ModCode, map);

	InitOperator(RAND, RandCode, map);

	//�߼�-��������
	InitOperator(CMP, CompareCode, map);
	InitOperator(NON, NonCode, map);

	return 0;
}

void CreateFuncTable(NoaFile * file,FuncTable * table) {
	uint8 code[4];
	for (uint32 i = 4; i < file->length;i++)
	{
		if (file->data[i-4]==fun)
		{
			code[0] = file->data[i - 3];
			code[1] = file->data[i - 2];
			code[2] = file->data[i - 1];
			code[3] = file->data[i];
			InsertFuncNode(table, code, (i + 1));
		}
	}
}

void InitConstantPool() {
	//��ʼ��������
	stringPool = InitStringPool(STRINGPOOLSIZE);
	intPool = InitIntPool(INTPOOLSIZE);
	floatPool = InitFloatPool(FLOATPOOLSIZE);
}

int Run(NoaFile* file) {

	if (file==nullptr)
	{
		printf("error:����Noa����ʧ��\n");
		return -1;
	}
	//�����ڴ棺(1024*1024)Byte
	ram = InitRAM(RAMSIZE);
	
	//��ʼ��ָ���
	OperatorMap opMap;
	
	InitOperatorMap(&opMap, OPMAPSIZE);

	CreateOperator(&opMap);
	
	//��ʼ������ջ
	InitCodeStack(&callStack,CALLINDEXSIZE);
	int64 pcIndex = 0;
	PC = &pcIndex;
	//��ʼ��������
	InitFuncTable(&funcTable);
	CreateFuncTable(file,&funcTable);
	
	//��ʼ��������
	InitConstantPool();

	//��ȡ��������ַ
	pcIndex = GetMainFuncIndex(&funcTable);
	if (pcIndex<0)
	{
		printf("[error]:�޷��ҵ�������ڵ�ַ: .Main:\n");
		free(ram);
		free(file->data);
		free(file);
		free(stringPool);
		free(intPool);
		free(floatPool);
		return -1;
	}

	const uint8* fileData = file->data;
	const OperatorMap* opMapAdress = &opMap;
	pc = fileData[pcIndex];
	
	uint8* parameters = parameter.paramer;
	clock_t startTime = clock();
	while (1)
	{
		//�����ٶ�̫��
		pc = fileData[pcIndex];
		if (pc == quit) 
		{
			pcIndex = 0;
			break;
		}
		memcpy(parameters, &fileData[(pcIndex + 1)], 20 * sizeof(uint8));
		const Operator * op = GetOperator(opMapAdress,pc);//Ч����
		op->func();

	}

	std::cout << std::endl << "[warring]:����ʱ��:" << double(clock() - startTime) / CLOCKS_PER_SEC << std::endl;

	//�ͷż������Դ
	free(ram);
	free(file->data);
	free(file);
	free(stringPool);
	free(intPool);
	free(floatPool);
	return 0;
}
