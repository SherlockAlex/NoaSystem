#include "Compiler.h"
#include "malloc.h"
#include "string.h"

int64* data;
char code[100];

void Compile(FILE * file,FILE* outFile) {
	data = (int64*)malloc(sizeof(int64));
	char mess = 0;
	int i = 0;

	while (fscanf(file, "%s", code) != EOF)
	{
		int len = strlen(code);

		if (strcmp(code, ".Main:") == 0)
		{
			data[i] = fun;
			fwrite(data, sizeof(int64), 1, outFile);
			data[i] = _start;
			fwrite(data, sizeof(int64), 1, outFile);
			data[i] = _start;
			fwrite(data, sizeof(int64), 1, outFile);
			data[i] = _start;
			fwrite(data, sizeof(int64), 1, outFile);
			data[i] = _start;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "mov") == 0)
		{
			data[i] = mov;
			fwrite(data, sizeof(int64), 1, outFile);

		}
		else if (strcmp(code, ".end") == 0)
		{
			data[i] = _end;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (code[0] == '.' && code[len - 1] == ':')
		{
			//�����Ķ���
			data[i] = fun;
			fwrite(data, sizeof(int64), 1, outFile);

			char* funcName = (char*)malloc(sizeof(char) * (len - 2));
			for (int k = 0; k < len - 2; k++) {
				funcName[k] = code[k + 1];
			}
			funcName[len - 2] = '\0';
			//printf("\n%s",funcName);
			//int num = 0;
			//sscanf(funcName, "%x", &num);
			uint32 hashCode = HashCode(funcName);
			uint8* nameCode = (uint8*)malloc(sizeof(uint8));
			nameCode[0] = (hashCode & 0xff000000) >> 24;//��λ
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x00ff0000) >> 16;
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x0000ff00) >> 8;
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x000000ff);//��λ
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

		}


		else if (strcmp(code, "outstr") == 0)
		{
			data[i] = prts;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "out") == 0)
		{
			data[i] = prt;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "add") == 0)
		{
			data[i] = add;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "sub") == 0)
		{
			data[i] = sub;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "and") == 0)
		{
			data[i] = AND;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "mst") == 0)
		{
			data[i] = mst;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "write") == 0)
		{
			data[i] = wtm;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "read") == 0) {
			data[i] = rfm;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "or") == 0)
		{
			data[i] = OR;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "mul") == 0)
		{
			data[i] = mul;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "div") == 0)
		{
			data[i] = div;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "loop") == 0)
		{
			data[i] = loop;
			fwrite(data, sizeof(int64), 1, outFile);
			//����4���ֽڵĵ�ַ

			//Ȼ��������ȡ������
			fscanf(file, "%s", code);

			//uint32 nameHashCode = HashCode(code);
			//printf("������:%s,����:%d,hash:%x\n", code, strlen(code), nameHashCode);

			uint32 hashCode = HashCode(code);
			uint8* nameCode = (uint8*)malloc(sizeof(uint8));
			nameCode[0] = (hashCode & 0xff000000) >> 24;//��λ
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x00ff0000) >> 16;
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x0000ff00) >> 8;
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x000000ff);//��λ
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

		}
		else if (strcmp(code, "call") == 0)
		{
			data[i] = call;
			fwrite(data, sizeof(int64), 1, outFile);

			//Ȼ��������ȡ������
			fscanf(file, "%s", code);

			//uint32 nameHashCode = HashCode(code);
			//printf("������:%s,����:%d,hash:%x\n", code, strlen(code), nameHashCode);

			uint32 hashCode = HashCode(code);
			uint8* nameCode = (uint8*)malloc(sizeof(uint8));
			nameCode[0] = (hashCode & 0xff000000) >> 24;//��λ
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x00ff0000) >> 16;
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x0000ff00) >> 8;
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x000000ff);//��λ
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			/*data[i] = nameHashCode;
			fwrite(data, sizeof(int64), 1, outFile);*/
		}
		/*else if (strcmp(code, "return") == 0)
		{
			data[i] = recall;
			fwrite(data, sizeof(int64), 1, outFile);
		}*/
		else if (strcmp(code, ".quit") == 0)
		{
			data[i] = quit;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "andbyte") == 0)
		{
			data[i] = ANDB;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "orbyte") == 0)
		{
			data[i] = ORB;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "if") == 0)
		{
			data[i] = IF;
			fwrite(data, sizeof(int64), 1, outFile);

			fscanf(file, "%s", code);//��ȡ����������Ϊ��ַ

			//һ��ĵ�ַ���ͣ�����Ϊ4���ֽ�
			uint8 codeNum = HashCode8(code);
			printf("�ַ���:%s,����:%d,hash:%x\n", code, strlen(code), codeNum);
			data[i] = codeNum;
			fwrite(data, sizeof(int64), 1, outFile);

			fscanf(file, "%s", code);//��ȡִ�к�����ַ

			uint32 hashCode = HashCode(code);
			uint8* nameCode = (uint8*)malloc(sizeof(uint8));
			nameCode[0] = (hashCode & 0xff000000) >> 24;//��λ
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x00ff0000) >> 16;
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x0000ff00) >> 8;
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x000000ff);//��λ
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

		}

		else if (strcmp(code, "else") == 0)
		{
			data[i] = ELSE;
			fwrite(data, sizeof(int64), 1, outFile);

			fscanf(file, "%s", code);//��ȡ����������Ϊ��ַ

			//һ��ĵ�ַ���ͣ�����Ϊ4���ֽ�
			uint8 codeNum = HashCode8(code);
			printf("�ַ���:%s,����:%d,hash:%x\n", code, strlen(code), codeNum);
			data[i] = codeNum;
			fwrite(data, sizeof(int64), 1, outFile);

			fscanf(file, "%s", code);//��ȡִ�к�����ַ

			uint32 hashCode = HashCode(code);
			uint8* nameCode = (uint8*)malloc(sizeof(uint8));
			nameCode[0] = (hashCode & 0xff000000) >> 24;//��λ
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x00ff0000) >> 16;
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x0000ff00) >> 8;
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

			nameCode[0] = (hashCode & 0x000000ff);//��λ
			data[i] = nameCode[0];
			fwrite(data, sizeof(int64), 1, outFile);

		}

		else if (strcmp(code, "compare") == 0)
		{
			data[i] = CMP;
			fwrite(data, sizeof(int64), 1, outFile);
		}

		else if (strcmp(code, "eax") == 0)
		{
			data[i] = eax;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "ebx") == 0)
		{
			data[i] = ebx;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "ecx") == 0)
		{
			data[i] = ecx;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "edx") == 0)
		{
			data[i] = edx;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "ax") == 0)
		{
			data[i] = ax;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "qx") == 0)
		{
			data[i] = qx;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "lopc") == 0)
		{
			//ѭ��������
			data[i] = loopcounter;
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "string") == 0)
		{

			//�����ַ�������

			fscanf(file, "%s", code);				//��ȡ������

			short startPos = 0;						//����Ҫ������ڴ��ַ����ʼ��ַ
			//startPos = HashCode8(code);
			startPos = HashCode16(code);				//�ַ����ٳ������еĵ�ַ
			//������ʼ��ַ�ĸ�λ�͵�λ
			uint8 posL = (uint8)(startPos & 0xff);
			uint8 posH = (uint8)((startPos >> 8) & 0xff);
			printf("�ַ�����:%s,����:%d,hashcode:%x\n", code, strlen(code), startPos);

			fscanf(file, "%s", code);				//��ȡ�ַ�������ֵ

			char* str = code;						//�ַ���ֵ
			//int64 startPos = 0;

			int64 charIndex = 0;

			int64 strs;

			for (uint8 j = 0; j < strlen(str); j++) {
				if (str[j] == 34) {
					continue;
				}
				if (str[j] == '\0') {
					break;
				}
				strs = STRING;
				fwrite(&strs, sizeof(int64), 1, outFile);

				strs = posH;
				fwrite(&strs, sizeof(int64), 1, outFile);

				strs = posL;
				fwrite(&strs, sizeof(int64), 1, outFile);

				strs = charIndex;
				fwrite(&strs, sizeof(int64), 1, outFile);

				strs = str[j];
				fwrite(&strs, sizeof(int64), 1, outFile);

				charIndex++;
			}

		}

		else if (strcmp(code, "strread") == 0) {
			//��ȡ�ַ������ڴ���

			data[i] = STRREADER;
			fwrite(data, sizeof(int64), 1, outFile);

			fscanf(file, "%s", code);				//��ȡ������
			short startPos = 0;						//����Ҫ������ڴ��ַ����ʼ��ַ
			//startPos = HashCode8(code);
			startPos = HashCode16(code);				//�ַ����ٳ������еĵ�ַ
			//������ʼ��ַ�ĸ�λ�͵�λ
			uint8 posL = (uint8)(startPos & 0xff);
			uint8 posH = (uint8)((startPos >> 8) & 0xff);

			data[i] = posH;
			fwrite(data, sizeof(int64), 1, outFile);

			data[i] = posL;
			fwrite(data, sizeof(int64), 1, outFile);

		}

		else if (strcmp(code, "int") == 0) {
			//��ȡ�ַ������ڴ���

			data[i] = INT;
			fwrite(data, sizeof(int64), 1, outFile);

			fscanf(file, "%s", code);				//��ȡ������
			short startPos = 0;						//����Ҫ������ڴ��ַ����ʼ��ַ
			//startPos = HashCode8(code);
			startPos = HashCode16(code);				//�ַ����ٳ������еĵ�ַ
			//������ʼ��ַ�ĸ�λ�͵�λ
			uint8 posL = (uint8)(startPos & 0xff);
			uint8 posH = (uint8)((startPos >> 8) & 0xff);

			data[i] = posH;
			fwrite(data, sizeof(int64), 1, outFile);

			data[i] = posL;
			fwrite(data, sizeof(int64), 1, outFile);

			//����ֵ

			fscanf(file, "%s", code);				//��ȡ��ֵ

			int value = 0;
			//value = atoi(code);
			sscanf(code, "%d", &value);
			printf("��ȡ���������ַ�:%s,intֵΪ:%d\n", code, value);

			data[i] = (uint8)((value) >> 24);
			fwrite(data, sizeof(int64), 1, outFile);
			data[i] = (uint8)((value) >> 16);
			fwrite(data, sizeof(int64), 1, outFile);
			data[i] = (uint8)((value) >> 8);
			fwrite(data, sizeof(int64), 1, outFile);
			data[i] = (uint8)((value));
			fwrite(data, sizeof(int64), 1, outFile);
		}

		else if (strcmp(code, "intread") == 0) {
			//��ȡ�ַ������ڴ���

			data[i] = INTREADER;
			fwrite(data, sizeof(int64), 1, outFile);

			fscanf(file, "%s", code);				//��ȡ������
			short startPos = 0;						//����Ҫ������ڴ��ַ����ʼ��ַ
			//startPos = HashCode8(code);
			startPos = HashCode16(code);				//�ַ����ٳ������еĵ�ַ
			//������ʼ��ַ�ĸ�λ�͵�λ
			uint8 posL = (uint8)(startPos & 0xff);
			uint8 posH = (uint8)((startPos >> 8) & 0xff);

			data[i] = posH;
			fwrite(data, sizeof(int64), 1, outFile);

			data[i] = posL;
			fwrite(data, sizeof(int64), 1, outFile);

		}

		else if (strcmp(code, "float") == 0) {
			//��ȡ�ַ������ڴ���

			data[i] = FLOAT;
			fwrite(data, sizeof(int64), 1, outFile);

			fscanf(file, "%s", code);				//��ȡ������
			short startPos = 0;						//����Ҫ������ڴ��ַ����ʼ��ַ
			//startPos = HashCode8(code);
			startPos = HashCode16(code);				//�ַ����ٳ������еĵ�ַ
			//������ʼ��ַ�ĸ�λ�͵�λ
			uint8 posL = (uint8)(startPos & 0xff);
			uint8 posH = (uint8)((startPos >> 8) & 0xff);

			data[i] = posH;
			fwrite(data, sizeof(int64), 1, outFile);

			data[i] = posL;
			fwrite(data, sizeof(int64), 1, outFile);

			//����ֵ

			fscanf(file, "%s", code);				//��ȡ��ֵ

			/*int value = 0;
			value = atoi(code);*/

			float num = 0;
			sscanf(code, "%f", &num);

			int value = *(int*)&num;

			printf("��ȡ���������ַ�:%s,intֵΪ:%d\n", code, value);

			data[i] = (uint8)((value) >> 24);
			fwrite(data, sizeof(int64), 1, outFile);
			data[i] = (uint8)((value) >> 16);
			fwrite(data, sizeof(int64), 1, outFile);
			data[i] = (uint8)((value) >> 8);
			fwrite(data, sizeof(int64), 1, outFile);
			data[i] = (uint8)((value) & 0xff);
			fwrite(data, sizeof(int64), 1, outFile);
		}

		else if (strcmp(code, "floatread") == 0) {
			//��ȡ�ַ������ڴ���

			data[i] = FLOATREADER;
			fwrite(data, sizeof(int64), 1, outFile);

			fscanf(file, "%s", code);				//��ȡ������
			short startPos = 0;						//����Ҫ������ڴ��ַ����ʼ��ַ
			//startPos = HashCode8(code);
			startPos = HashCode16(code);				//�ַ����ٳ������еĵ�ַ
			//������ʼ��ַ�ĸ�λ�͵�λ
			uint8 posL = (uint8)(startPos & 0xff);
			uint8 posH = (uint8)((startPos >> 8) & 0xff);

			data[i] = posH;
			fwrite(data, sizeof(int64), 1, outFile);

			data[i] = posL;
			fwrite(data, sizeof(int64), 1, outFile);

		}

		//��ֵ
		else if (strcmp(code, "\'A\'") == 0)
		{
			data[i] = 'A';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'B\'") == 0)
		{
			data[i] = 'B';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'C\'") == 0)
		{
			data[i] = 'C';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'D\'") == 0)
		{
			data[i] = 'D';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'E\'") == 0)
		{
			data[i] = 'E';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'F\'") == 0)
		{
			data[i] = 'F';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'G\'") == 0)
		{
			data[i] = 'G';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'H\'") == 0)
		{
			data[i] = 'H';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'I\'") == 0)
		{
			data[i] = 'I';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'J\'") == 0)
		{
			data[i] = 'J';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'K\'") == 0)
		{
			data[i] = 'K';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'L\'") == 0)
		{
			data[i] = 'L';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'M\'") == 0)
		{
			data[i] = 'M';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'N\'") == 0)
		{
			data[i] = 'N';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'O\'") == 0)
		{
			data[i] = 'O';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'P\'") == 0)
		{
			data[i] = 'P';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'Q\'") == 0)
		{
			data[i] = 'Q';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'R\'") == 0)
		{
			data[i] = 'R';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'S\'") == 0)
		{
			data[i] = 'S';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'T\'") == 0)
		{
			data[i] = 'T';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'U\'") == 0)
		{
			data[i] = 'U';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'V\'") == 0)
		{
			data[i] = 'V';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'W\'") == 0)
		{
			data[i] = 'W';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'X\'") == 0)
		{
			data[i] = 'X';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'Y\'") == 0)
		{
			data[i] = 'Y';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'Z\'") == 0)
		{
			data[i] = 'Z';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\' \'") == 0)
		{
			data[i] = ' ';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'\n\'") == 0)
		{
			data[i] = '\n';
			fwrite(data, sizeof(int64), 1, outFile);
		}

		else if (strcmp(code, "\'a\'") == 0)
		{
			data[i] = 'a';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'b\'") == 0)
		{
			data[i] = 'b';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'c\'") == 0)
		{
			data[i] = 'c';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'d\'") == 0)
		{
			data[i] = 'd';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'e\'") == 0)
		{
			data[i] = 'e';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'f\'") == 0)
		{
			data[i] = 'f';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'g\'") == 0)
		{
			data[i] = 'g';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'h\'") == 0)
		{
			data[i] = 'h';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'i\'") == 0)
		{
			data[i] = 'i';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'j\'") == 0)
		{
			data[i] = 'j';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'k\'") == 0)
		{
			data[i] = 'k';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'l\'") == 0)
		{
			data[i] = 'l';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'m\'") == 0)
		{
			data[i] = 'm';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'n\'") == 0)
		{
			data[i] = 'n';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'o\'") == 0)
		{
			data[i] = 'o';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'p\'") == 0)
		{
			data[i] = 'p';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'q\'") == 0)
		{
			data[i] = 'q';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'r\'") == 0)
		{
			data[i] = 'r';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'s\'") == 0)
		{
			data[i] = 's';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'t\'") == 0)
		{
			data[i] = 't';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'u\'") == 0)
		{
			data[i] = 'u';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'v\'") == 0)
		{
			data[i] = 'v';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'w\'") == 0)
		{
			data[i] = 'w';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'x\'") == 0)
		{
			data[i] = 'x';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'y\'") == 0)
		{
			data[i] = 'y';
			fwrite(data, sizeof(int64), 1, outFile);
		}
		else if (strcmp(code, "\'z\'") == 0)
		{
			data[i] = 'z';
			fwrite(data, sizeof(int64), 1, outFile);
		}

		else if (code[0] == '#')
		{

			//��ֵע��ģ��ֱ��ע�͵�
			continue;
		}

		else
		{
			//��������
			if (code[0] == '0' && code[1] == 'x' || isNum(code))
			{
				int num = 0;
				sscanf(code, "%x", &num);
				data[i] = num;
			}
			//�ַ���
			else
			{
				//һ��ĵ�ַ���ͣ�����Ϊ4���ֽ�
				uint8 codeNum = HashCode8(code);
				printf("�ַ���:%s,����:%d,hash:%x\n", code, strlen(code), codeNum);
				data[i] = codeNum;
			}
			fwrite(data, sizeof(int64), 1, outFile);
		}
	}

	free(data);

}