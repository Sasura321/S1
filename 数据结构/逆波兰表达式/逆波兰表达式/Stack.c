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

//��ʼ��
void StackInit(Stack *pStack)
{
	pStack->top = 0;
}

//����
void StackDestory(Stack *pStack)
{
	pStack->top = 0;
}

//����(ֻ�ܴ�ջ��)
void StackPush(Stack *pStack, StackDataType data)
{
	//������û��Խ��
	assert(pStack->top < MAX_SIZE);
	pStack->array[pStack->top++] = data;
}

//ɾ��(ֻ��ɾ��ջ��)
void StackPop(Stack *pStack)
{
	//��������Ϊ��
	assert(pStack->top > 0);
	pStack->top--;
}

//���ң�ֻ�ܲ鿴ջ��Ԫ�أ�
StackDataType StackTop(const Stack *pStack)
{
	//��������Ϊ��
	assert(pStack->top > 0);
	return pStack->array[pStack->top - 1];
}

//����ջ�ĳ���
int StackSize(const Stack *pStack)
{
	return pStack->top;
}

//�ж��Ƿ�ջ��
int StackFull(const Stack *pStack)
{
	return pStack->top >= MAX_SIZE;
}

//�ж��Ƿ�ջ��
int StackEmpty(const Stack *pStack)
{
	return pStack->top <= 0;
}