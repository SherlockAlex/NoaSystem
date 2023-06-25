#ifndef NOAVM_RAM_H
#define NOAVM_RAM_H

#include "type.h"
#include <string>

extern uint8 noaRegister[7];//�Ĵ���


//�����ڴ�
typedef struct RAM {
	uint8* buffer;//ram�ڴ�
	int bufferSize;
}RAM;


//�ַ���������
typedef struct StringPool {
	std::string* buffer;
	int bufferSize;
}StringPool;

//���ͳ�����
typedef struct IntPool {
	int* buffer;
	int bufferSize;
};

//������������

extern RAM * InitRAM(int ramSize);





#endif // !NOAVM_RAM_H
