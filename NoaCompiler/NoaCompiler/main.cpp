#include "Compiler.h"

int64 header[3] = {
	'N','O','A'
};

int main(int argc,char * argv[]) {

	if (argc<=1) {
		return -1;
	}

	//���ļ����Ϊnoa�ļ�
	FILE* outFile = fopen(".\\test.noa", "w");
	if (outFile==nullptr) {
		printf("�����ļ�ʧ��\n");
		return -1;
	}
	fwrite(header, sizeof(int64), 3, outFile);
	fclose(outFile);

	outFile = fopen(".\\test.noa", "a+");

	if (outFile == nullptr) {
		printf("�����ļ�ʧ��\n");
		return -1;
	}

	FILE* file = fopen(argv[1], "r");
	if (file==nullptr) {
		printf("���ļ�ʧ��\n");
		return -1;
	}
	
	Compile(file,outFile);

	fclose(file);
	fclose(outFile);

	

	return 0;
}