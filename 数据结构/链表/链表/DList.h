#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
双向
循环
带头
*/

typedef struct DListNode
{
	int data;
	struct DListNode *prev;
	struct DListNode *next;
}	DListNode;

// 初始化
void DListInit(DListNode **ppHead)
{
	assert(ppHead != NULL);
	DListNode *pHead = (DListNode *)malloc(sizeof(DListNode));

	pHead->next = pHead;
	pHead->prev = pHead;

	*ppHead = pHead;
}

// 保留头结点
void DListClear(DListNode *pHead)
{
	DListNode *cur = pHead->next;
	DListNode *next;

	while (cur != pHead)
	{
		next = cur->next;
		free(cur);
	}

	pHead->next = pHead;
	pHead->prev = pHead;
}

// 销毁头结点
void DListDestroy(DListNode **ppHead)
{
	DListClear(*ppHead);
	free(*ppHead);
	*ppHead = NULL;
}

void DListInsert(DListNode *pHead, DListNode *pos, int data)
{
	DListNode *node = (DListNode *)malloc(sizeof(DListNode));
	node->data = data;

	node->prev = pos->prev;
	node->next = pos;
	pos->prev->next = node;
	pos->prev = node;
}

// 头插
void DListPushFront(DListNode *pHead, int data)
{
	DListInsert(pHead, pHead->next, data);
}

// 尾插
void DListPushBack(DListNode *pHead, int data)
{
	DListInsert(pHead, pHead, data);
}

void DListErase(DListNode *pHead, DListNode *pos)
{
	(void)pHead;
	assert(pos != pHead);

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

// 头删
void DListPopFront(DListNode *pHead)
{
	// 链表为空，pHead->next == pHead;
	DListErase(pHead,pHead->next);
}

// 尾删
void DListPopBack(DListNode *pHead)
{
	DListErase(pHead, pHead->prev);
}

