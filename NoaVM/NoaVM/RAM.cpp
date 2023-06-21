#include "RAM.h"
#include "malloc.h"
#include "type.h"

int64 noaRegister[7] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00};

RAM * InitRAM(int ramSize) {
	RAM* ram = (RAM*)malloc(sizeof(RAM));
	ram->bufferSize = ramSize;
	ram->buffer = (int64*)malloc(ramSize * sizeof(int64));
	return ram;
}