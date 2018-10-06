#pragma once
#include "SeqList.h"

// 使用场景
void test()
{
	// 1.
	SeqList seqList;
	SeqListInit(&seqList);	// 1. seqList， 2. &seqList	// 1）. 指针空间更小 2）.改变值 

	// 2.
	//SeqList *pSeqList;
	//pSeqList = SeqListInit();

	printf("插入：\n");
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 7);
	SeqListPushBack(&seqList, 8);
	SeqListPushBack(&seqList, 9);
	SeqListPrint(&seqList);

	printf("尾插：\n");
	SeqListPopBack(&seqList);
	SeqListPrint(&seqList);

	printf("头插：\n");
	SeqListPushFront(&seqList, 4);
	SeqListPushFront(&seqList, 3);
	SeqListPushFront(&seqList, 2);
	SeqListPushFront(&seqList, 1);
	SeqListPrint(&seqList);

	printf("中间插：\n");
	SeqListInsert(&seqList, 4, 5);
	SeqListPrint(&seqList);

	printf("尾删：\n");
	SeqListPopBack(&seqList);
	SeqListPrint(&seqList);

	printf("头删：\n");
	SeqListPopFront(&seqList);
	SeqListPrint(&seqList);

	printf("中间删：\n");
	SeqListErase(&seqList, 5);
	SeqListPrint(&seqList);

	printf("查找：\n");
	printf("%d\n", SeqListFind(&seqList, 5));
	printf("%d\n", SeqListFind2(&seqList, 5));
	
	printf("根据数据删除：\n");
	SeqListRemoveAll1(&seqList,2);
	SeqListPrint(&seqList);

	SeqListRemoveAll2(&seqList, 3);
	SeqListPrint(&seqList);

	SeqListRemoveAll3(&seqList, 4);
	SeqListPrint(&seqList);
}
