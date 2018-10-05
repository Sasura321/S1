#pragma once

#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode {
	DataType data;
	struct ListNode *next;
}	ListNode;

// 初始化/销毁
void ListInit(ListNode **ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

void ListDestroy(ListNode **ppFirst)
{
	// TODO:
	*ppFirst = NULL;
}

// 增删查改
static ListNode * CreateNode(DataType data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

//头插
void ListPushFront(ListNode **ppFirst, DataType data)
{
	assert(ppFirst != NULL);
	// 考虑特殊情况，链表为空 *ppFirst == NULL

	// 正常情况
	// 1. 指针 vs 指向空间；从堆上申请空间
	ListNode *newNode = CreateNode(data);
	newNode->next = *ppFirst;

	*ppFirst = newNode;
}

//尾插
void ListPushBack(ListNode **ppFirst, DataType data)
{
	ListNode *newNode = CreateNode(data);

	// 特殊情况，找倒数第一个 -> 至少有一个，所以特殊情况是链表为空
	if (*ppFirst == NULL) {
		*ppFirst = newNode;
		return;
	}

	// 通常情况
	ListNode *cur = *ppFirst;
	while (cur->next != NULL) {
		cur = cur->next;
	}

	// cur 就是最后一个结点
	cur->next = newNode;
}

// 删除
//头删
void ListPopFront(ListNode **ppFirst)
{
	assert(ppFirst != NULL);	// 变量地址不为 NULL
	assert(*ppFirst != NULL);	// 不能是空链表

	ListNode *del = *ppFirst;
	*ppFirst = del->next;

	free(del);	// 谨记
}


void ListPopBack(ListNode **ppFirst)
{
	assert(ppFirst != NULL);	// 变量地址不为 NULL
	assert(*ppFirst != NULL);	// 不能是空链表

	// 链表中只有一个结点
	if ((*ppFirst)->next == NULL) {
		free(*ppFirst);
		*ppFirst = NULL;
		return;
	}

	// 正常情况
	ListNode *del;
	ListNode *cur = *ppFirst;

	while (cur->next->next != NULL) {
		cur = cur->next;
	}

	del = cur->next;
	cur->next = NULL;
	free(del);
}


// 查找
ListNode * ListFind(ListNode *first, DataType data)
{
	// 顺序查找，去遍历
	for (ListNode *cur = first; cur != NULL; cur = cur->next) {
		if (data == cur->data) {
			return cur;
		}
	}

	return NULL;
}

// 在结点前做插入（结点 pos 肯定在链表中 && pos 不是空【链表不是空】）
void ListInsert(ListNode **ppFirst, ListNode *pos, DataType data)
{
	// 头插
	if (*ppFirst == pos) {
		ListPushFront(ppFirst, data);
		return;	// 记得 return，否则下面加上 else
	}

	ListNode *cur = *ppFirst;
	// 找 pos 的前一个结点
	while (cur->next != pos) {
		cur = cur->next;
	}

	// 插入新结点
	ListNode *newNode = CreateNode(data);	// 一定要申请空间
	newNode->next = cur->next;	// or pos;
	cur->next = newNode;
}

// 删除指定结点（结点 pos 肯定在链表中 && pos 不是空【链表不是空】
void ListErase(ListNode **ppFirst, ListNode *pos)
{
	// 头删
	if (*ppFirst == pos) {
		ListPopFront(ppFirst);
		return;	// 记得 return，否则下面加上 else
	}

	ListNode *cur = *ppFirst;
	// 找 pos 的前一个结点
	while (cur->next != pos) {
		cur = cur->next;
	}

	cur->next = pos->next;
	free(pos);	// 记得
}

void Test()
{
	ListNode *first;
	ListInit(&first);	// 传值 1. first	传地址 2. &first
	// 链表是一条空链表， first == NULL

	// first 会变化
	ListPushBack(&first, 1);

	// 以后 first 不变了
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);

	ListNode *result = ListFind(first, 2);	// 传地址 or 传值?
	ListInsert(&first, result, 0);
}

