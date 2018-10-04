#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode{
	DataType data;
	struct ListNode *next;
}	ListNode;

//��ʼ��
void ListInit(ListNode **ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

//����
void ListDestroy(ListNode **ppFirst)
{
	*ppFirst = NULL;
}

/*
��ɾ���
*/
struct ListNode *CreateNode(DataType data)
{

	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

//ͷ��
void ListPushFront(ListNode **ppFirst,DataType data)
{
	assert(ppFirst != NULL);
	ListNode *newNode = CreateNode(data);
	newNode->data = data;
	newNode->next = *ppFirst;
	*ppFirst = newNode;
}

// β��
void LisstPushBack(ListNode **ppFirst, DataType data)
{
	ListNode *newNode = CreateNode(data);

	// �������������Ϊ��
	if (*ppFirst == NULL)
	{
		*ppFirst = newNode;
		return;
	}

	// ͨ�����
	ListNode *cur = *ppFirst;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	// cur �������һ�����
	cur->next = newNode;
}

//ͷɾ 
void ListPopFront(ListNode **ppFirst)
{
	assert(ppFirst != NULL);
	assert(*ppFirst != NULL);

	ListNode *del = *ppFirst;
	*ppFirst = (*ppFirst)->next;
	free(del);
}

// βɾ
void ListPopBack(ListNode **ppFirst)
{
	assert(ppFirst != NULL); // ������ַ��Ϊ��
	assert(*ppFirst != NULL); // �����ǿ�����

	// ������ֻ��һ�����
	if ((*ppFirst)->next == NULL)
	{
		free(*ppFirst);
		*ppFirst = NULL;
		return;
	}

	// �������
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

//����
ListNode *ListFind(ListNode *first, DataType data)
{
	//˳����ң�ȥ����
	for (ListNode *cur = first; cur != NULL; cur = cur->next){
		if (cur->data == data){
			return cur;
		}
	}

	return NULL;
}

//�ڽ��ǰ�����루��� pos �϶��������� && pos ���ǿա������ǿա���
void ListInsert(ListNode **ppFirst, ListNode *pos, DataType data)
{
	//ͷ��
	if (*ppFirst == pos){
		ListPushFront(ppFirst, data);
		return;
	}

	ListNode *cur = *ppFirst;
	//�ҵ� pos ǰһ�����
	while (cur->next != pos){
		cur = cur->next;
	}

	//�����½��
	ListNode *newNode = CreateNode(data);
	newNode->next = pos;
	cur->next = newNode;
}

//ɾ��ָ����㣨��� pos �϶��������� && pos ���ǿա������ǿա���
void ListErase(ListNode **ppFirst, ListNode *pos)
{
	//ͷɾ
	if (*ppFirst == pos){
		ListPopFront(ppFirst);
		return;
	}

	ListNode *cur = *ppFirst;
	//�ҵ� pos ǰһ�����
	while (cur->next != pos){
		cur = cur->next;
	}

	//ɾ�����
	cur->next = pos->next;
	free(pos);
}

// ��ӡ����
void ListPrint(ListNode *first)
{
	for (ListNode *cur = first; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}
	printf("NULL\n");
}