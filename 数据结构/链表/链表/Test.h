#pragma once
#include"List.h"
#include"DList.h"

void TestList()
{
	ListNode *first = NULL;
	ListInit(&first);

	printf("ͷ�壺\n");
	ListPushFront(&first, 4);
	ListPushFront(&first, 3);
	ListPushFront(&first, 2);
	ListPushFront(&first, 1);
	ListPrint(first);

	printf("β�壺\n");
	LisstPushBack(&first, 5);
	LisstPushBack(&first, 6);
	LisstPushBack(&first, 7);
	ListPrint(first);

	printf("ͷɾ��\n");
	ListPopFront(&first);
	ListPrint(first);

	printf("βɾ��\n");
	ListPopBack(&first);
	ListPrint(first);

	printf("���ң�\n");
	ListFind(first, 5);
	ListPrint(first);
	ListFind(first, 100);
	ListPrint(first);

	printf("��ָ����λ�ò���ɾ����\n");
	ListNode *result = ListFind(first, 2);
	ListInsert(&first, result, 0);
	ListPrint(first);
	ListErase(&first, result);
	ListPrint(first);
}

void TestDList()
{

	DListNode *pHead;
	DListInit(&pHead);

	printf("ͷ�壺\n");
	DListPushFront(pHead, 3);
	DListPushFront(pHead, 2);
	DListPushFront(pHead, 1);

	printf("β�壺\n");
	DListPushBack(pHead, 4);
	DListPushBack(pHead, 5);
	DListPushBack(pHead, 6);

	printf("ͷɾ��\n");
	DListPopFront(pHead);

	printf("βɾ��\n");
	DListPopBack(pHead);

}