#pragma once
#include "Heap.h"

void test()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int size = sizeof(array) / sizeof(int);

	Heap heap;
	HeapInit(&heap, array, size);
	HeapMakeHeap(&heap);

	HeapPush(&heap, 100);
	printf("%d\n", HeapTop(&heap));

	printf("建堆完成\n");
}

void TestSort()
{
	int array[] = { 1, 4, 9, 4, 2, 7, 8, 5, 3, 6, 2, 2, 3 };
	int size = sizeof(array) / sizeof(int);

	HeapSort(array, size);

	printf("成功\n");
}

void TestTopK()
{
	int array[] = { 1, 4, 9, 4, 2, 7, 8, 5, 3, 6, 2, 2, 3 };
	int size = sizeof(array) / sizeof(int);

	int *r = TopK(array, size, 3);

	printf("成功\n");
}