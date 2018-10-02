#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct ListNode{
	DataType data;
	struct ListNode *next;
} ListNode;

//²åÈëµ¥Á´±í
void ListPushBack(ListNode **ppFirst, DataType data)
{
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	if (*ppFirst == NULL){
		*ppFirst = newNode;
	}

	ListNode *cur = *ppFirst;
	while (cur->next != NULL){
		cur = cur->next;
	}
	cur->next = newNode;
}