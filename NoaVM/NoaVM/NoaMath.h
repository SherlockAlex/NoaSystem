#ifndef NOAVM_NOAMATH_H
#define NOAVM_NOAMATH_H

#include "type.h"

//将一个长为length的字节流key映射为min和max
extern int64 HashCode(uint8* key, int64 length, int64 min, int64 max);

#endif // !NOAVM_NOAMATH_H


