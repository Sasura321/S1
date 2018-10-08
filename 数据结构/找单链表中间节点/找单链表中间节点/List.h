#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct ListNode{
	DataType data;
	struct ListNode *next;
} ListNode;

//插入链表
void ListPushBack(ListNode **ppFirst,DataType data)
{
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	if (*ppFirst == NULL){
		*ppFirst = newNode;
		return;
	}

	ListNode *cur = *ppFirst;
	while (cur->next != NULL){
		cur = cur->next;
	}
	cur->next = newNode;
}

/*
查找单链表的中间节点，要求只能遍历一次链表
*/
void FindMid(ListNode *first)
{
	ListNode *fast = first;
	ListNode *slow = first;

	while (1){
		fast = fast->next;
		if (fast == NULL){
			break;
		}
		fast = fast->next;
		if (fast == NULL){
			break;
		}
		slow = slow->next;
	}

	printf("%d\n", slow->data);
}