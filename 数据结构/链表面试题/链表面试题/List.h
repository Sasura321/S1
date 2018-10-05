#pragma once

#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode {
	DataType data;
	struct ListNode *next;
}	ListNode;

// ��ʼ��/����
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

// ��ɾ���
static ListNode * CreateNode(DataType data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

//ͷ��
void ListPushFront(ListNode **ppFirst, DataType data)
{
	assert(ppFirst != NULL);
	// �����������������Ϊ�� *ppFirst == NULL

	// �������
	// 1. ָ�� vs ָ��ռ䣻�Ӷ�������ռ�
	ListNode *newNode = CreateNode(data);
	newNode->next = *ppFirst;

	*ppFirst = newNode;
}

//β��
void ListPushBack(ListNode **ppFirst, DataType data)
{
	ListNode *newNode = CreateNode(data);

	// ����������ҵ�����һ�� -> ������һ���������������������Ϊ��
	if (*ppFirst == NULL) {
		*ppFirst = newNode;
		return;
	}

	// ͨ�����
	ListNode *cur = *ppFirst;
	while (cur->next != NULL) {
		cur = cur->next;
	}

	// cur �������һ�����
	cur->next = newNode;
}

// ɾ��
//ͷɾ
void ListPopFront(ListNode **ppFirst)
{
	assert(ppFirst != NULL);	// ������ַ��Ϊ NULL
	assert(*ppFirst != NULL);	// �����ǿ�����

	ListNode *del = *ppFirst;
	*ppFirst = del->next;

	free(del);	// ����
}


void ListPopBack(ListNode **ppFirst)
{
	assert(ppFirst != NULL);	// ������ַ��Ϊ NULL
	assert(*ppFirst != NULL);	// �����ǿ�����

	// ������ֻ��һ�����
	if ((*ppFirst)->next == NULL) {
		free(*ppFirst);
		*ppFirst = NULL;
		return;
	}

	// �������
	ListNode *del;
	ListNode *cur = *ppFirst;

	while (cur->next->next != NULL) {
		cur = cur->next;
	}

	del = cur->next;
	cur->next = NULL;
	free(del);
}


// ����
ListNode * ListFind(ListNode *first, DataType data)
{
	// ˳����ң�ȥ����
	for (ListNode *cur = first; cur != NULL; cur = cur->next) {
		if (data == cur->data) {
			return cur;
		}
	}

	return NULL;
}

// �ڽ��ǰ�����루��� pos �϶��������� && pos ���ǿա������ǿա���
void ListInsert(ListNode **ppFirst, ListNode *pos, DataType data)
{
	// ͷ��
	if (*ppFirst == pos) {
		ListPushFront(ppFirst, data);
		return;	// �ǵ� return������������� else
	}

	ListNode *cur = *ppFirst;
	// �� pos ��ǰһ�����
	while (cur->next != pos) {
		cur = cur->next;
	}

	// �����½��
	ListNode *newNode = CreateNode(data);	// һ��Ҫ����ռ�
	newNode->next = cur->next;	// or pos;
	cur->next = newNode;
}

// ɾ��ָ����㣨��� pos �϶��������� && pos ���ǿա������ǿա�
void ListErase(ListNode **ppFirst, ListNode *pos)
{
	// ͷɾ
	if (*ppFirst == pos) {
		ListPopFront(ppFirst);
		return;	// �ǵ� return������������� else
	}

	ListNode *cur = *ppFirst;
	// �� pos ��ǰһ�����
	while (cur->next != pos) {
		cur = cur->next;
	}

	cur->next = pos->next;
	free(pos);	// �ǵ�
}

void Test()
{
	ListNode *first;
	ListInit(&first);	// ��ֵ 1. first	����ַ 2. &first
	// ������һ�������� first == NULL

	// first ��仯
	ListPushBack(&first, 1);

	// �Ժ� first ������
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);

	ListNode *result = ListFind(first, 2);	// ����ַ or ��ֵ?
	ListInsert(&first, result, 0);
}

