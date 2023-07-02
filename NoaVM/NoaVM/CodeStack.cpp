#include "NoaRuntime.h"
#include "malloc.h"
#include "stdio.h"

/*
* 为什么需要函数栈的概念，首先第一次加载程序，函数的起始地址会被入栈，并实时发生更新，当
*/



int64 codeIndexBuffer[CALLINDEXSIZE];
void InitCodeStack(CodeStack* stack,int length)
{
	stack->top = -1;
	stack->codeIndex = codeIndexBuffer;
	//stack->codeIndex = (int64*)malloc(length*sizeof(int64));
	if (stack->codeIndex == nullptr)
	{
		printf("[error]:创建栈失败\n");
	}
}

void IncreaseStack(CodeStack* stack) {
	//发现不够用时
}

void PushCodeStack(CodeStack* stack, int64 code)
{

	if (stack->top==1023)
	{
		printf("[error]:函数入栈失败,栈满\n");
		return;
	}
	stack->top = stack->top + 1;
	stack->codeIndex[stack->top] = code;

}
int64 PopCodeStack(CodeStack* stack)
{
	//出栈

	if (stack->top==-1)
	{
		printf("[error]:当前栈为空\n");
		return -1;
	}
	int64 code = stack->codeIndex[stack->top];
	stack->top = stack->top - 1;
	return code;

}
extern int64 GetHeadOfStack(CodeStack* stack)
{
	//获取栈顶
	if (stack->top==-1) {
		printf("[error]:访问栈顶失败\n");
		return -1;
	}
	return stack->codeIndex[stack->top];
}