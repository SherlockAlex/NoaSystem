#include "NoaRuntime.h"
#include "malloc.h"
#include "stdio.h"

/*
* Ϊʲô��Ҫ����ջ�ĸ�����ȵ�һ�μ��س��򣬺�������ʼ��ַ�ᱻ��ջ����ʵʱ�������£���
*/

void InitCodeStack(CodeStack* stack,int length)
{
	stack->count = 0;
	stack->codeIndex = (int64*)malloc(length*sizeof(int64));
}

void IncreaseStack(CodeStack* stack) {
	//���ֲ�����ʱ
}

void PushCodeStack(CodeStack* stack, int64 code)
{
	//��ջ
	//printf("��ջ�ɹ�\n");
	if (stack->count<=0) {
		stack->codeIndex[0] = code;
		return;
	}
	for (int i = stack->count - 1; i >= 0;i--) {
		stack->codeIndex[i + 1] = stack->codeIndex[i];
	}
	stack->codeIndex[0] = code;
	stack->count++;
	return;
}
int64 PopCodeStack(CodeStack* stack)
{
	//��ջ
	if (stack->count<=0) {
		return 0;
	}
	int64 code = stack->codeIndex[0];
	for (int i = 0; i < stack->count - 1;i++) {
		stack->codeIndex[i] = stack->codeIndex[i + 1];
	}
	stack->count--;
	return code;
}
extern int64 GetHeadOfStack(CodeStack* stack)
{
	//��ȡջ��
	return stack->codeIndex[0];
}