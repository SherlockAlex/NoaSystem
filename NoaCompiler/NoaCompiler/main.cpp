#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "NoaCode.h"
#include "malloc.h"

int64* data;

char code[65535];

int64 header[3] = {
	'N','O','A'
};

int main(int argc,char * argv[]) {

	if (argc<=1) {
		return -1;
	}

	//将文件输出为noa文件
	FILE* outFile = fopen(".\\test.noa", "w");
	fwrite(header, sizeof(int64), 3, outFile);
	fclose(outFile);

	outFile = fopen(".\\test.noa", "a+");
	

	FILE* file = fopen(argv[1], "r");
	if (file==nullptr) {
		printf("打开文件失败\n");
		return -1;
	}
	data = (int64*)malloc(sizeof(int64));
	char mess;
	int i = 0;

	while ((mess=fgetc(file))!=EOF)
	{
		fscanf(file, "%s", code);
		
		if (strcmp(code,"mov")==0) 
		{
			data[i] = mov;
			
		}
		else if (strcmp(code, "ver") == 0)
		{
			data[i] = ver;

		}
		else if (strcmp(code, "prts") == 0)
		{
			data[i] = prts;
		}
		else if (strcmp(code, "prt") == 0)
		{
			data[i] = prt;
		}
		else if (strcmp(code, "add") == 0)
		{
			data[i] = add;
		}
		else if (strcmp(code, "sub") == 0)
		{
			data[i] = sub;
		}
		else if (strcmp(code, "and") == 0)
		{
			data[i] = AND;
		}
		else if (strcmp(code, "mst") == 0)
		{
			data[i] = mst;
		}
		else if (strcmp(code, "wtm") == 0)
		{
			data[i] = wtm;
		}
		else if (strcmp(code, "or") == 0)
		{
			data[i] = OR;
		}
		else if (strcmp(code, "mul") == 0)
		{
			data[i] = mul;
		}
		else if (strcmp(code, "div") == 0)
		{
			data[i] = div;
		}
		else if (strcmp(code, "loop") == 0)
		{
			data[i] = loop;
		}
		else if (strcmp(code, "call") == 0)
		{
			data[i] = call;
		}
		else if (strcmp(code, "recall") == 0)
		{
			data[i] = recall;
		}
		else if (strcmp(code, "quit") == 0)
		{
			data[i] = quit;
		}

		else if(strcmp(code, "eax") == 0)
		{
			data[i] = eax;
		}
		else if (strcmp(code, "ebx") == 0)
		{
			data[i] = ebx;
		}
		else if (strcmp(code, "ecx") == 0)
		{
			data[i] = ecx;
		}
		else if (strcmp(code, "edx") == 0)
		{
			data[i] = edx;
		}
		else if (strcmp(code, "ax") == 0)
		{
			data[i] = ax;
		}
		else if (strcmp(code, "qx") == 0)
		{
			data[i] = qx;
		}

		//数值
		else if (strcmp(code, "\'A\'") == 0)
		{
			data[i] = 'A';
		}
		else if (strcmp(code, "\'B\'") == 0)
		{
			data[i] = 'B';
		}
		else if (strcmp(code, "\'C\'") == 0)
		{
			data[i] = 'C';
		}
		else if (strcmp(code, "\'D\'") == 0)
		{
			data[i] = 'D';
		}
		else if (strcmp(code, "\'E\'") == 0)
		{
			data[i] = 'E';
		}
		else if (strcmp(code, "\'F\'") == 0)
		{
			data[i] = 'F';
		}
		else if (strcmp(code, "\'G\'") == 0)
		{
			data[i] = 'G';
		}
		else if (strcmp(code, "\'H\'") == 0)
		{
			data[i] = 'H';
		}
		else if (strcmp(code, "\'I\'") == 0)
		{
			data[i] = 'I';
		}
		else if (strcmp(code, "\'J\'") == 0)
		{
			data[i] = 'J';
		}
		else if (strcmp(code, "\'K\'") == 0)
		{
			data[i] = 'K';
		}
		else if (strcmp(code, "\'L\'") == 0)
		{
			data[i] = 'L';
		}
		else if (strcmp(code, "\'M\'") == 0)
		{
			data[i] = 'M';
		}
		else if (strcmp(code, "\'N\'") == 0)
		{
			data[i] = 'N';
		}
		else if (strcmp(code, "\'O\'") == 0)
		{
			data[i] = 'O';
		}
		else if (strcmp(code, "\'P\'") == 0)
		{
			data[i] = 'P';
		}
		else if (strcmp(code, "\'Q\'") == 0)
		{
			data[i] = 'Q';
		}
		else if (strcmp(code, "\'R\'") == 0)
		{
			data[i] = 'R';
		}
		else if (strcmp(code, "\'S\'") == 0)
		{
			data[i] = 'S';
		}
		else if (strcmp(code, "\'T\'") == 0)
		{
			data[i] = 'T';
		}
		else if (strcmp(code, "\'U\'") == 0)
		{
			data[i] = 'U';
		}
		else if (strcmp(code, "\'V\'") == 0)
		{
			data[i] = 'V';
		}
		else if (strcmp(code, "\'W\'") == 0)
		{
			data[i] = 'W';
		}
		else if (strcmp(code, "\'X\'") == 0)
		{
			data[i] = 'X';
		}
		else if (strcmp(code, "\'Y\'") == 0)
		{
			data[i] = 'Y';
		}
		else if (strcmp(code, "\'Z\'") == 0)
		{
			data[i] = 'Z';
		}
		else if (strcmp(code, "\' \'") == 0)
		{
			data[i] = ' ';
		}
		else if (strcmp(code, "\'\n\'") == 0)
		{
			data[i] = '\n';
		}

		else if (strcmp(code, "\'a\'") == 0)
		{
			data[i] = 'a';
		}
		else if (strcmp(code, "\'b\'") == 0)
		{
			data[i] = 'b';
		}
		else if (strcmp(code, "\'c\'") == 0)
		{
			data[i] = 'c';
		}
		else if (strcmp(code, "\'d\'") == 0)
		{
			data[i] = 'd';
		}
		else if (strcmp(code, "\'e\'") == 0)
		{
			data[i] = 'e';
		}
		else if (strcmp(code, "\'f\'") == 0)
		{
			data[i] = 'f';
		}
		else if (strcmp(code, "\'g\'") == 0)
		{
			data[i] = 'g';
		}
		else if (strcmp(code, "\'h\'") == 0)
		{
			data[i] = 'h';
		}
		else if (strcmp(code, "\'i\'") == 0)
		{
			data[i] = 'i';
		}
		else if (strcmp(code, "\'j\'") == 0)
		{
			data[i] = 'j';
		}
		else if (strcmp(code, "\'k\'") == 0)
		{
			data[i] = 'k';
		}
		else if (strcmp(code, "\'l\'") == 0)
		{
			data[i] = 'l';
		}
		else if (strcmp(code, "\'m\'") == 0)
		{
			data[i] = 'm';
		}
		else if (strcmp(code, "\'n\'") == 0)
		{
			data[i] = 'n';
		}
		else if (strcmp(code, "\'o\'") == 0)
		{
			data[i] = 'o';
		}
		else if (strcmp(code, "\'p\'") == 0)
		{
			data[i] = 'p';
		}
		else if (strcmp(code, "\'q\'") == 0)
		{
			data[i] = 'q';
		}
		else if (strcmp(code, "\'r\'") == 0)
		{
			data[i] = 'r';
		}
		else if (strcmp(code, "\'s\'") == 0)
		{
			data[i] = 's';
		}
		else if (strcmp(code, "\'t\'") == 0)
		{
			data[i] = 't';
		}
		else if (strcmp(code, "\'u\'") == 0)
		{
			data[i] = 'u';
		}
		else if (strcmp(code, "\'v\'") == 0)
		{
			data[i] = 'v';
		}
		else if (strcmp(code, "\'w\'") == 0)
		{
			data[i] = 'w';
		}
		else if (strcmp(code, "\'x\'") == 0)
		{
			data[i] = 'x';
		}
		else if (strcmp(code, "\'y\'") == 0)
		{
			data[i] = 'y';
		}
		else if (strcmp(code, "\'z\'") == 0)
		{
			data[i] = 'z';
		}

		else
		{
			//数字类型
			if (code[0]=='0'&&code[1] == 'x') {
				int64 num = 0;
				sscanf(code, "%x", &num);
				data[i] = num;
			}
			else
			{
				int64 num = atol(code);
				data[i] = num;
			}
		}



		fwrite(data, sizeof(int64), 1, outFile);
	}

	fclose(file);

	//fwrite(data, sizeof(int64), i, outFile);
	fclose(outFile);

	free(data);

	return 0;
}