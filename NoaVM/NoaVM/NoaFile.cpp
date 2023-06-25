#include "NoaFile.h"
#include <malloc.h>

NoaFile* InitNoaFile(uint8* data, int64 length) {
	NoaFile* noaFile = (NoaFile*)malloc(sizeof(NoaFile));
	noaFile->data = data;
	noaFile->length = length;
	return noaFile;
}