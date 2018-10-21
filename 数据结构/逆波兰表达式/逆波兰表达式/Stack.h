#ifndef __STACK_H__
#define __STACK_H__

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define MAX_SIZE (100)

typedef char StackDataType;

typedef struct Stack
{
	StackDataType array[MAX_SIZE];
	int top;
}	Stack;

void StackInit(Stack *pStack);
void StackDestory(Stack *pStack);
void StackPush(Stack *pStack, StackDataType data);
void StackPop(Stack *pStack);

StackDataType StackTop(const Stack *pStack);
int StackSize(const Stack *pStack);
int StackFull(const Stack *pStack);
int StackEmpty(const Stack *pStack);

#endif  __STACK_H__