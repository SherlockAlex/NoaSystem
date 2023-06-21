#include "NoaFile.h"
#include "NoaRuntime.h"
#include "NoaFunc.h"
#include "NoaCode.h"
#include "type.h"

int64array noaHeap[1024] = {
	{'h','e','l','l','o',' ','w','o','r','l','d','\n'},
	{'n','o','a','\n'}
};

int64 data[] = {
    
	//±‡–¥noa≤‚ ‘¥˙¬Î
	mov,eax,10,
	mov,ebx,66,
	mul,eax,ebx,
	prt,eax,0x81,

	recall,

	mov,ax,0x1125,
	call,0,
	quit


};



int main(int argc,char * argv[]) {
	NoaFile* noaFile = nullptr;
	if (argc<2) {
		noaFile = InitNoaFile(data,19,8);
	}
	else
	{
		noaFile = loadFile(argv[1]);
	}
	
	run(noaFile);

	return 0;
}