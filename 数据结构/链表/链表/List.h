#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode{
	DataType data;
	struct ListNode *next;
}	ListNode;

//初始化
void ListInit(ListNode **ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

//销毁
void ListDestroy(ListNode **ppFirst)
{
	*ppFirst = NULL;
}

/*
增删查改
*/
struct ListNode *CreateNode(DataType data)
{

	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

//头插
void ListPushFront(ListNode **ppFirst,DataType data)
{
	assert(ppFirst != NULL);
	ListNode *newNode = CreateNode(data);
	newNode->data = data;
	newNode->next = *ppFirst;
	*ppFirst = newNode;
}

// 尾插
void LisstPushBack(ListNode **ppFirst, DataType data)
{
	ListNode *newNode = CreateNode(data);

	// 特殊情况，链表为空
	if (*ppFirst == NULL)
	{
		*ppFirst = newNode;
		return;
	}

	// 通常情况
	ListNode *cur = *ppFirst;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	// cur 就是最后一个结点
	cur->next = newNode;
}

//头删 
void ListPopFront(ListNode **ppFirst)
{
	assert(ppFirst != NULL);
	assert(*ppFirst != NULL);

	ListNode *del = *ppFirst;
	*ppFirst = (*ppFirst)->next;
	free(del);
}

// 尾删
void ListPopBack(ListNode **ppFirst)
{
	assert(ppFirst != NULL); // 变量地址不为空
	assert(*ppFirst != NULL); // 不能是空链表

	// 链表中只有一个结点
	if ((*ppFirst)->next == NULL)
	{
		free(*ppFirst);
		*ppFirst = NULL;
		return;
	}

	// 正常情况
	ListNode *del;
	ListNode *cur = *ppFirst;

	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}

	del = cur->next;
	cur->next = NULL;
	free(del);
}

//查找
ListNode *ListFind(ListNode *first, DataType data)
{
	//顺序查找，去遍历
	for (ListNode *cur = first; cur != NULL; cur = cur->next){
		if (cur->data == data){
			return cur;
		}
	}

	return NULL;
}

//在结点前做插入（结点 pos 肯定在链表中 && pos 不是空【链表不是空】）
void ListInsert(ListNode **ppFirst, ListNode *pos, DataType data)
{
	//头插
	if (*ppFirst == pos){
		ListPushFront(ppFirst, data);
		return;
	}

	ListNode *cur = *ppFirst;
	//找到 pos 前一个结点
	while (cur->next != pos){
		cur = cur->next;
	}

	//插入新结点
	ListNode *newNode = CreateNode(data);
	newNode->next = pos;
	cur->next = newNode;
}

//删除指定结点（结点 pos 肯定在链表中 && pos 不是空【链表不是空】）
void ListErase(ListNode **ppFirst, ListNode *pos)
{
	//头删
	if (*ppFirst == pos){
		ListPopFront(ppFirst);
		return;
	}

	ListNode *cur = *ppFirst;
	//找到 pos 前一个结点
	while (cur->next != pos){
		cur = cur->next;
	}

	//删除结点
	cur->next = pos->next;
	free(pos);
}

// 打印链表
void ListPrint(ListNode *first)
{
	for (ListNode *cur = first; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}
	printf("NULL\n");
}