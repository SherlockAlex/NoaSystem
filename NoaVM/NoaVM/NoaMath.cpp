#include "NoaMath.h"

int64 HashCode(uint8* key, int64 length,int64 min,int64 max)
{
	//根据输入的字符来生成一个哈希值
	int64 hash[4];				//key最长只有50个字符
	int64 base = 857;
	int64 mod = (max-1);
	hash[0] = key[0];
	int64 i = 1;
	for (i = 1; i < length; i++) {
		hash[i] = (hash[i - 1] * base + key[i]) % mod;
	}

	int64 hash2[4];
	int64 base2 = 4391;
	int64 mod2 = (max-1);
	hash2[0] = hash[i - 1];
	int64 j = 1;
	for (j = 1; j < length; j++) {
		hash2[j] = (hash2[j - 1] * base2 + key[length - 1 - j]) & mod2;
	}

	int64 hash3[4];				//key最长只有50个字符
	int64 base3 = 9719;
	int64 mod3 = (max - 1);
	hash3[0] = hash2[j-1];
	int64 k = 1;
	for (k = 1; k < length; k++) {
		hash3[k] = (hash3[k - 1] * base3 + key[k]) % mod3;
	}

	return hash3[k - 1] + min;//返回值不能为0
}
