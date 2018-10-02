#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct ListNode{
	DataType data;
	struct ListNode *next;
} ListNode;

// 初始化
void ListInit(ListNode **ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

//从尾到头打印单链表
void PrintReverse(ListNode *first)
{
	assert(first != NULL);

	ListNode *end = NULL;

	while (end != first){
		ListNode *cur = first;

		while (cur->next != end){
			cur = cur->next;
		}
		printf(" %d ", cur->data);
		end = cur;
	}
	printf("\n");
}