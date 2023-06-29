#include "HashMath.h"
#include "string.h"
#include "stdio.h"

uint8 HashCode8(char* key) {
	//根据输入的字符来生成一个哈希值
	uint8 hash[50];				//key最长只有50个字符
	int base = 857;
	uint8 mod = 255;
	hash[0] = key[0];
	int i = 1;
	int length = strlen(key);
	for (i = 1; i < length; i++) {
		hash[i] = (hash[i - 1] * base + key[i]) % mod;
	}

	uint8 hash2[50];
	int base2 = 1009;
	uint8 mod2 = 255;
	hash2[0] = hash[i - 1];
	int j = 1;
	for (j = 1; j < length; j++) {
		hash2[j] = (hash2[j - 1] * base2 + key[length - 1 - j]) & mod2;
	}

	return hash2[j - 1] + 1;//返回值不能为0
	//return hash2[j - 1];//返回值可以为0
}

short HashCode16(char* key) {
	//根据输入的字符来生成一个哈希值
	uint8 hash[50];				//key最长只有50个字符
	int base = 857;
	uint8 mod = 65535;
	hash[0] = key[0];
	int i = 1;
	int length = strlen(key);
	for (i = 1; i < length; i++) {
		hash[i] = (hash[i - 1] * base + key[i]) % mod;
	}

	uint8 hash2[50];
	int base2 = 1009;
	uint8 mod2 = 65535;
	hash2[0] = hash[i - 1];
	int j = 1;
	for (j = 1; j < length; j++) {
		hash2[j] = (hash2[j - 1] * base2 + key[length - 1 - j]) & mod2;
	}

	return hash2[j - 1] + 1;//返回值不能为0
}


uint32 HashCode(char* key) {
	//根据输入的字符来生成一个哈希值
	uint32 hash[50];				//key最长只有50个字符
	uint32 base = 857;
	uint32 mod = 4294967295;
	hash[0] = key[0];
	uint32 i = 1;
	uint32 length = strlen(key);
	for (i = 1; i < length;i++) {
		hash[i] = (hash[i - 1] * base + key[i]) % mod;
	}

	uint32 hash2[50];
	uint32 base2 = 2111;
	uint32 mod2 = 4294967295;
	hash2[0] = hash[i-1];
	uint32 j = 1;
	for (j = 1; j < length;j++) {
		hash2[j] = (hash2[j - 1] * base2 + key[length - 1 - j]) & mod2;
	}

	//return hash3[k-1]+1;//返回值不能为0
	return hash2[j - 1]+1;//返回值可以为0
}

bool isNum(char* str) {
	//scanf("%s", &input_num);
	if (strspn(str,"0123456789") == strlen(str))
	{
		printf("%s是数字\n",str);
		return true;
	}
	printf("%s不是数字\n", str);
	return false;
}
