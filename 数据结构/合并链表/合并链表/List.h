#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode {
	DataType data;
	struct ListNode *next;
}	ListNode;

void ListPush(ListNode **ppFirst, DataType data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	if (*ppFirst == NULL) {
		*ppFirst = newNode;
		return;
	}
	ListNode *cur = *ppFirst;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = newNode;
}

/*
*合并两个有序链表，并使合成的链表有序
*/

ListNode *MergeOrderdList(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	ListNode *result = NULL; //结果链表
	ListNode *tail = NULL;   //结果链表中的最后一个结点，方便尾插
	ListNode *next;          //保存遍历结点过程中的下一个结点

	while (cur1 != NULL && cur1 != NULL){
		if (cur1->data <= cur2->data){
			//应该取链表 1 的节点
			if (result != NULL){
				tail->next = cur1;

			}
		}
	}

}

ListNode* UnionList(ListNode *list1, ListNode *list2)
{
	assert(list1);
	assert(list2);

	ListNode *p1 = list1;
	ListNode *p2 = list2;
	ListNode *result = NULL;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data){
			ListPush(&result, p1->data);
			p1 = p1->next;
		}
		else{
			ListPush(&result, p2->data);
			p2 = p2->next;
		}
	}

	// 一个链表为空了
	if (p1 == NULL) {
		while (p2 != NULL){
			ListPush(&result, p2->data);
			p2 = p2->next;
		}
	}

	if (p2 == NULL) {
		while (p1 != NULL){
			ListPush(&result, p1->data);
			p1 = p1->next;
		}
	}

	return result;
}

void PrintResult(ListNode* result)
{
	ListNode *cur;

	for (cur = result; cur != NULL; cur = cur->next)
	{
		printf("%d  ", cur->data);
	}
}