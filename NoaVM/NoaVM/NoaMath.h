#ifndef NOAVM_NOAMATH_H
#define NOAVM_NOAMATH_H

#include "type.h"

//��һ����Ϊlength���ֽ���keyӳ��Ϊmin��max
extern int64 HashCode(const uint8* key,const int64 length,const int64 min,const int64 max);
extern uint32 ByteToInt(const uint8 * byte);

#endif // !NOAVM_NOAMATH_H


