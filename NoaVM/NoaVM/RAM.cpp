#include "RAM.h"
#include "malloc.h"
#include "type.h"

uint8 noaRegister[7] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00};

RAM * InitRAM(int ramSize) {
	RAM* ram = (RAM*)malloc(sizeof(RAM));
	ram->bufferSize = ramSize;
	ram->buffer = (uint8*)malloc(ramSize * sizeof(uint8));
	return ram;
}