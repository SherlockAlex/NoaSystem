#include "NoaFile.h"
#include <malloc.h>
#include <iostream>

NoaFile* InitNoaFile(static uint8* data, int64 length) {
	NoaFile* noaFile = (NoaFile*)malloc(sizeof(NoaFile));
	if (noaFile == nullptr)
	{
		printf("[error]:创建Noa文件失败\n");
		return nullptr;
	}
	noaFile->data = data;
	noaFile->length = length;
	return noaFile;
}