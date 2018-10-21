#include "Stack.h"

//typedef char StackDataType;
//
//#define MAX_SIZE (100)
//
//typedef struct Stack
//{
//	StackDataType array[MAX_SIZE];
//	int top;
//}	Stack;

//初始化
void StackInit(Stack *pStack)
{
	pStack->top = 0;
}

//销毁
void StackDestory(Stack *pStack)
{
	pStack->top = 0;
}

//增加(只能从栈顶)
void StackPush(Stack *pStack, StackDataType data)
{
	//条件：没有越界
	assert(pStack->top < MAX_SIZE);
	pStack->array[pStack->top++] = data;
}

//删除(只能删除栈顶)
void StackPop(Stack *pStack)
{
	//条件：不为空
	assert(pStack->top > 0);
	pStack->top--;
}

//查找（只能查看栈顶元素）
StackDataType StackTop(const Stack *pStack)
{
	//条件：不为空
	assert(pStack->top > 0);
	return pStack->array[pStack->top - 1];
}

//计算栈的长度
int StackSize(const Stack *pStack)
{
	return pStack->top;
}

//判断是否栈满
int StackFull(const Stack *pStack)
{
	return pStack->top >= MAX_SIZE;
}

//判断是否栈空
int StackEmpty(const Stack *pStack)
{
	return pStack->top <= 0;
}