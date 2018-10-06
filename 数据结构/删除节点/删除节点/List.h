#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct ListNode{
	DataType data;
	struct ListNode *next;
} ListNode;

//插入单链表
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

/*
删除一个无头单链表的非尾节点（不能遍历链表）
*/
