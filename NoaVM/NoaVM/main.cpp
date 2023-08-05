#include "NoaFile.h"
#include "NoaRuntime.h"
#include "NoaFunc.h"
#include "NoaCode.h"
#include "type.h"
#include "stdio.h"

int main(int argc,char * argv[]) 
{
	
	if (argc<2) {
		printf("[error]:没有任何noa文件可以执行\n");
		/*static NoaFile* noaFile = nullptr;
		noaFile = LoadFile("./test1.noa");
		Run(noaFile);*/
		return 0;
	}
	else
	{
		static NoaFile* noaFile = nullptr;
		noaFile = LoadFile(argv[1]);
		Run(noaFile);
	}
	
	return 0;
}