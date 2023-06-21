#ifndef NOAVM_NOAFILE_H
#define NOAVM_NOAFILE_H

#include "type.h"

typedef struct NoaFile {
	int64* data;
	int length;
	int codeCount;
}NoaFile;

extern NoaFile* InitNoaFile(int64 * data,int length,int codeCount);

#endif // !NOAVM_NOAFILE_H
