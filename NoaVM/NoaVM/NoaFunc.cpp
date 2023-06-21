#include "NoaFunc.h"
#include "stdio.h"
#include "NoaCode.h"
#include "type.h"

void version(RAM* ram, int64 dpIndex, int64 dpLength, int* pcIndex) {
	printf("NoaVM version:0.0.1\n");
}

void printStr(RAM* ram, int64 dpIndex, int64 dpLength, int* pcIndex) {
	for (int64 i = 0; i < noaRegister[3];i++) {
		printf("%c",ram->buffer[i]);
	}
}

void printRegister(RAM* ram, int64 registerIndex, int64 flags, int* pcIndex) {
	//��ӡ�Ĵ��������ֵ
	switch (flags)
	{
		case 0x80:
			//��ӡ�ַ�
			printf("%c",noaRegister[registerIndex]);
			break;
		case 0x81:
			printf("%d", noaRegister[registerIndex]);
			break;
		default:
			break;
	}
}

void moveToRegister(RAM* ram, int64 registerIndex, int64 data, int* pcIndex) {
	//��ram��λ��ΪdpIndex�����ݷ���Ĵ�����
	noaRegister[registerIndex] = data;
}

void addNumBToA(RAM* ram, int64 adresss1, int64 adresss2, int* pcIndex)
{
	//ʹ��addǰ��������ʹ��movָ����ַŵ��Ĵ����ڲ�
	noaRegister[adresss1] += noaRegister[adresss2];
}

void ASubB(RAM* ram, int64 adresss1, int64 adresss2, int* pcIndex)
{
	//��������
	noaRegister[adresss1] -= noaRegister[adresss2];
}

void noaAnd(RAM* ram, int64 adress1, int64 adress2, int* pcIndex)
{
	//������
	noaRegister[adress1] = (noaRegister[adress1] & noaRegister[adress2]);
}

void heapToRAM(RAM* ram, int64 pramater1, int64 data, int* pcIndex)
{	//mov,ecx,pos
	//mov,edx,len
	//mst,
	int64 heapPos = noaRegister[2];
	int64 length = noaRegister[3];
	for(int64 i=0;i<length;i++)
	{
		ram->buffer[i] = noaHeap[heapPos][i];
	}
	
}

void WriteToRAM(RAM* ram, int64 ramindex, int64 data, int* pcIndex)
{
	//���ڱ�������õ�
	ram->buffer[ramindex] = data;
}

void noaOr(RAM* ram, int64 adress1, int64 adress2, int* pcIndex)
{
	noaRegister[adress1] = (noaRegister[adress1] | noaRegister[adress2]);
}

void multiply(RAM* ram, int64 adress1, int64 adress2, int* pcIndex) {
	noaRegister[adress1] *= noaRegister[adress2];
}
void divide(RAM* ram, int64 adress1, int64 adress2, int* pcIndex) {
	if (noaRegister[adress2]==0) {
		noaRegister[adress1] = 0xffffffff;
		return;
	}

	noaRegister[adress1] /= noaRegister[adress2];

}

void callCode(RAM* ram, int64 adress1, int64 adress2, int* pcIndex) {
	//call ��ַ
	//���Ƚ���ǰpc��ֵ����������Ȼ������Ŀ���ַ��ʼִ��Ŀ�꺯��
	//���Ƚ�pcIndex���浽spc��
	if (noaRegister[ax]!=0x1125)
	{
		//ֻ�е����ֵΪ0x1125ʱ��������ת,��������
		return;
	}
	noaRegister[spc] = (*pcIndex);
	*pcIndex = adress1-2;

}

void recallCode(RAM* ram, int64 adress1, int64 adress2, int* pcIndex) {
	//�ָ��ֳ�
	//recall
	if (noaRegister[ax]!=0x1125) {
		return;
	}
	*pcIndex = noaRegister[spc]+1;
	noaRegister[spc] = 0x00;
}

