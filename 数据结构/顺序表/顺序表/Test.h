#pragma once
#include "SeqList.h"

// ʹ�ó���
void test()
{
	// 1.
	SeqList seqList;
	SeqListInit(&seqList);	// 1. seqList�� 2. &seqList	// 1��. ָ��ռ��С 2��.�ı�ֵ 

	// 2.
	//SeqList *pSeqList;
	//pSeqList = SeqListInit();

	printf("���룺\n");
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 7);
	SeqListPushBack(&seqList, 8);
	SeqListPushBack(&seqList, 9);
	SeqListPrint(&seqList);

	printf("β�壺\n");
	SeqListPopBack(&seqList);
	SeqListPrint(&seqList);

	printf("ͷ�壺\n");
	SeqListPushFront(&seqList, 4);
	SeqListPushFront(&seqList, 3);
	SeqListPushFront(&seqList, 2);
	SeqListPushFront(&seqList, 1);
	SeqListPrint(&seqList);

	printf("�м�壺\n");
	SeqListInsert(&seqList, 4, 5);
	SeqListPrint(&seqList);

	printf("βɾ��\n");
	SeqListPopBack(&seqList);
	SeqListPrint(&seqList);

	printf("ͷɾ��\n");
	SeqListPopFront(&seqList);
	SeqListPrint(&seqList);

	printf("�м�ɾ��\n");
	SeqListErase(&seqList, 5);
	SeqListPrint(&seqList);

	printf("���ң�\n");
	printf("%d\n", SeqListFind(&seqList, 5));
	printf("%d\n", SeqListFind2(&seqList, 5));
	
	printf("��������ɾ����\n");
	SeqListRemoveAll1(&seqList,2);
	SeqListPrint(&seqList);

	SeqListRemoveAll2(&seqList, 3);
	SeqListPrint(&seqList);

	SeqListRemoveAll3(&seqList, 4);
	SeqListPrint(&seqList);
}
