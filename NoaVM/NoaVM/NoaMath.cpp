#include "NoaMath.h"
#include <iostream>

int64 HashCode(const uint8* key, const int64 length, const int64 min, const int64 max)
{
    const int64 base = 857;
    const int64 base2 = 4391;
    const int64 base3 = 9719;
    const int64 mod = (max - 1);
    const int64 shift = 10; // 2的幂次方的位移值

    int64 hash = key[0];
    int64 hash2 = key[length - 1];
    int64 hash3 = key[0];

    for (int64 i = 1, j = length - 2, k = 1; i < length; i++, j--, k++)
    {
        hash = ((hash << shift) + key[i]) & (mod - 1);
        hash2 = ((hash2 << shift) + key[j]) & (mod - 1);
        hash3 = ((hash3 << shift) + key[k]) & (mod - 1);
    }

    return (hash3 + min) & (mod - 1) + min;
}

//int64 HashCode(const uint8* key,const int64 length,const int64 min,const int64 max)
//{
//	//根据输入的字符来生成一个哈希值
//	int64 hash[4];				//key最长只有50个字符
//	const int64 base = 857;
//	const int64 mod = (max-1);
//	hash[0] = key[0];
//	int64 i = 1;
//	for (i = 1; i < length; i++) {
//		hash[i] = ((hash[i - 1] * base) + key[i]) % mod;
//	}
//
//	int64 hash2[4];
//	const int64 base2 = 4391;
//	const int64 mod2 = (max-1);
//	hash2[0] = hash[i - 1];
//	int64 j = 1;
//	for (j = 1; j < length; j++) {
//		hash2[j] = ((hash2[j - 1] * base2) + key[length - 1 - j]) % mod2;
//	}
//
//	int64 hash3[4];				//key最长只有50个字符
//	const int64 base3 = 9719;
//	const int64 mod3 = (max - 1);
//	hash3[0] = hash2[j-1];
//	int64 k = 1;
//	for (k = 1; k < length; k++) {
//		hash3[k] = ((hash3[k - 1] * base3) + key[k]) % mod3;
//	}
//
//	return hash3[k - 1] + min;//返回值不能为0
//}


uint32 ByteToInt(const uint8* byte) {
	const uint32 value = (uint32)(((byte[0] & 0xff) << 24) | ((byte[1] & 0xff) << 16) | ((byte[2] & 0xff) << 8) | (byte[3] & 0xff));
	//printf("byte:%x %x %x %x,value:%d\n",byte[0],byte[1],byte[2],byte[3], value);
	return value;
}