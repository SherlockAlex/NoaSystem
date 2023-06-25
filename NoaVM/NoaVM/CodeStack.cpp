#include "NoaRuntime.h"
#include "malloc.h"
#include "stdio.h"

/*
* 为什么需要函数栈的概念，首先第一次加载程序，函数的起始地址会被入栈，并实时发生更新，当
*/

void InitCodeStack(CodeStack* stack,int length)
{
	stack->count = 0;
	stack->codeIndex = (int64*)malloc(length*sizeof(int64));
}

void IncreaseStack(CodeStack* stack) {
	//发现不够用时
}

void PushCodeStack(CodeStack* stack, int64 code)
{
	//入栈
	//printf("入栈成功\n");
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
	//出栈
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
	//获取栈顶
	return stack->codeIndex[0];
}