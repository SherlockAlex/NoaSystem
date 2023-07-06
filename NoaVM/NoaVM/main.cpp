#include "NoaFile.h"
#include "NoaRuntime.h"
#include "NoaFunc.h"
#include "NoaCode.h"
#include "type.h"
#include "stdio.h"

int main(int argc,char * argv[]) 
{
	
	if (argc<2) {
		printf("[error]:û���κ�noa�ļ�����ִ��\n");
		return 0;
	}
	else
	{
		NoaFile* noaFile = nullptr;
		noaFile = LoadFile(argv[1]);
		Run(noaFile);
	}
	
	return 0;
}