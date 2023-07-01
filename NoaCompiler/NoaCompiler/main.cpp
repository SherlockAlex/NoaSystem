#include "Compiler.h"

int64 header[3] = {
	'N','O','A'
};

int main(int argc,char * argv[]) {

	if (argc<=1) {
		return -1;
	}

	//将文件输出为noa文件
	FILE* outFile = fopen(".\\test.noa", "w");
	if (outFile==nullptr) {
		printf("编译文件失败\n");
		return -1;
	}
	fwrite(header, sizeof(int64), 3, outFile);
	fclose(outFile);

	outFile = fopen(".\\test.noa", "a+");

	if (outFile == nullptr) {
		printf("编译文件失败\n");
		return -1;
	}

	FILE* file = fopen(argv[1], "r");
	if (file==nullptr) {
		printf("打开文件失败\n");
		return -1;
	}
	
	Compile(file,outFile);

	fclose(file);
	fclose(outFile);

	

	return 0;
}