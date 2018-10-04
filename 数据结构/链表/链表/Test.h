#pragma once
#include"List.h"
#include"DList.h"

void TestList()
{
	ListNode *first = NULL;
	ListInit(&first);

	printf("头插：\n");
	ListPushFront(&first, 4);
	ListPushFront(&first, 3);
	ListPushFront(&first, 2);
	ListPushFront(&first, 1);
	ListPrint(first);

	printf("尾插：\n");
	LisstPushBack(&first, 5);
	LisstPushBack(&first, 6);
	LisstPushBack(&first, 7);
	ListPrint(first);

	printf("头删：\n");
	ListPopFront(&first);
	ListPrint(first);

	printf("尾删：\n");
	ListPopBack(&first);
	ListPrint(first);

	printf("查找：\n");
	ListFind(first, 5);
	ListPrint(first);
	ListFind(first, 100);
	ListPrint(first);

	printf("在指定定位置插入删除：\n");
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

	printf("头插：\n");
	DListPushFront(pHead, 3);
	DListPushFront(pHead, 2);
	DListPushFront(pHead, 1);

	printf("尾插：\n");
	DListPushBack(pHead, 4);
	DListPushBack(pHead, 5);
	DListPushBack(pHead, 6);

	printf("头删：\n");
	DListPopFront(pHead);

	printf("尾删：\n");
	DListPopBack(pHead);

}