#include "NoaRuntime.h"
#include "malloc.h"
#include "stdio.h"

/*
* Ϊʲô��Ҫ����ջ�ĸ�����ȵ�һ�μ��س��򣬺�������ʼ��ַ�ᱻ��ջ����ʵʱ�������£���
*/



int64 codeIndexBuffer[CALLINDEXSIZE];
void InitCodeStack(CodeStack* stack,int length)
{
	stack->top = -1;
	stack->codeIndex = codeIndexBuffer;
	//stack->codeIndex = (int64*)malloc(length*sizeof(int64));
	if (stack->codeIndex == nullptr)
	{
		printf("[error]:����ջʧ��\n");
	}
}

void IncreaseStack(CodeStack* stack) {
	//���ֲ�����ʱ
}

void PushCodeStack(CodeStack* stack, int64 code)
{

	if (stack->top==1023)
	{
		printf("[error]:������ջʧ��,ջ��\n");
		return;
	}
	stack->top = stack->top + 1;
	stack->codeIndex[stack->top] = code;

}
int64 PopCodeStack(CodeStack* stack)
{
	//��ջ

	if (stack->top==-1)
	{
		printf("[error]:��ǰջΪ��\n");
		return -1;
	}
	int64 code = stack->codeIndex[stack->top];
	stack->top = stack->top - 1;
	return code;

}
extern int64 GetHeadOfStack(CodeStack* stack)
{
	//��ȡջ��
	if (stack->top==-1) {
		printf("[error]:����ջ��ʧ��\n");
		return -1;
	}
	return stack->codeIndex[stack->top];
}