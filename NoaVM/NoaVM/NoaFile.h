#ifndef NOAVM_NOAFILE_H
#define NOAVM_NOAFILE_H

#include "type.h"

typedef struct NoaFile {
	uint8* data;
	int64 length;
}NoaFile;

extern NoaFile* InitNoaFile(uint8 * data,int64 length);

#endif // !NOAVM_NOAFILE_H
