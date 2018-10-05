#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct ListNode{
	DataType data;
	struct ListNode *next;
} ListNode;

struct ListNode* CreateNode(DataType data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
}

void ListPushBack(ListNode **ppfirst, DataType data)
{
	ListNode *newNode = CreateNode(data);

	//特殊情况，单链表为空
	if (*ppfirst == NULL){
		*ppfirst = newNode;
		return;
	}

	//正常情况
	ListNode *cur = *ppfirst;
	while (cur->next != NULL){
		cur = cur->next;
		cur->next = newNode;
	}
}

// 逆置/反转单链表
ListNode *ReverseList(ListNode *first)
{
	ListNode *cur = first;
	ListNode *end = NULL;
	ListNode *result = NULL;

	while (end != first){
		while (cur->next != NULL){
			cur = cur->next;
		}
		ListPushBack(&result, cur->data);
		end = cur;
	}
	
	return result;
}

