#include "NoaFile.h"
#include <malloc.h>

NoaFile* InitNoaFile(int64* data, int length,int codeCount) {
	NoaFile* noaFile = (NoaFile*)malloc(sizeof(NoaFile));
	noaFile->data = data;
	noaFile->length = length;
	noaFile->codeCount = codeCount;
	return noaFile;
}