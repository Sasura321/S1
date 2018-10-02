#pragma once
#include "List.h"

static ListNode* CreateNode(DataType data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void ListPushBack(ListNode **ppfirst, DataType data)
{
	ListNode *newNode = CreateNode(data);

	// 特殊情况，链表为空
	if (*ppfirst == NULL){
		*ppfirst = newNode;
		return;
	}

	//正常情况
	ListNode *cur = *ppfirst;
	while (cur->next != NULL){
		cur = cur->next;
	}
	cur->next = newNode;
}

void ListTest()
{
	ListNode *first = NULL;
	ListInit(&first);

	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);

	PrintReverse(first);
}