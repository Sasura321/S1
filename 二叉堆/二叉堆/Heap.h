#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>


typedef struct Heap
{
	int array[100];
	int size;
}   Heap;

/*
初始化
*/
void HeapInit(Heap *pH, int source[], int size)
{
	for (int i = 0; i < size; i++){
		pH->array[i] = source[i];
	}
	pH->size = size;
}

static void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/*
向下调整
*/
void HeapAdjustDown(Heap *pH, int root)
{
	int parent = root;

	while (1){
		//先判断有没有孩子（叶子结点）
		// 数组角度去想	-> 孩子的下标是否越界
		// 只要判断左孩子的下标（因为是完全二叉树)
		int left = parent * 2 + 1;
		int right = parent * 2 + 2;
		//判断是否越界
		// 越界，没有左孩子，也肯定没有右孩子x
		while (left > pH->size){
			return;
		}

		//一定有左孩子
		int maxChild = left;
		while ((right > pH->size) && (pH->array[right] > pH->array[left])){
			//判断是否有右孩子，并且判断右孩子是否大于左孩子
			maxChild = right;
		}
		if (pH->array[parent] > pH->array[maxChild]){
			return;
		}

		// 交换 root 和 maxChild 下标所在的值
		int temp = pH->array[parent];
		pH->array[parent] = pH->array[maxChild];
		pH->array[maxChild] = temp;

		parent = maxChild;
	}
}

// 1. 数组的越界判断不对， 是否 == size
// 2. array[left] == NULL	array -> int[]	这么判断左孩子在不在是错的
// 3. 交换的时候，交换的下标，而不是下标所在的值
void HeapAdjustDown2(Heap *pH, size_t root)
{
	size_t parent = root;
	size_t left, right;
	size_t maxChild;

	left = 2 * root + 1;
	right = 2 * root + 2;
	while (left < (size_t)pH->size){
		maxChild = left;
		if (right < (size_t)pH->size && pH->array[left] < pH->array[right]){
			maxChild = right;
		}
		if (pH->array[maxChild] < pH->array[parent]){
			break;
		}

		Swap(pH->array + maxChild, pH->array + parent);
		parent = maxChild;
		left = 2 * parent + 1;
		right = 2 * parent + 2;
	}
	//left 不存在
}

/*
建堆
*/
void HeapMakeHeap(Heap *pH)
{
	//[(size-2)/2,2]   (向下取整)
	//最后一个叶子结点size-1，最后一个非叶子结点((size-1)-1)/2
	for (int i = (pH->size - 2) / 2; i >= 0; i--){
		HeapAdjustDown(pH, i);
	}
}

/*
删除
*/
//删除（取最后一个数据（size-1）,和 0所在位置的数据交换）
//然后进行向下调整，删（只能删除栈顶元素）
void HeapPop(Heap *pH)
{
	pH->array[0] = pH->array[pH->size - 1];
	pH->size--;

	HeapAdjustDown(pH, 0);
}

/*
取栈顶元素
*/
int HeapTop(const Heap *pH)
{
	return pH->array[0];
}

/*
向上调整
*/
void HeapAdjustUp(Heap *pH, int child)
{
	int parent;
	while (child > 0){
		parent = (child - 1) / 2;
		if (pH->array[parent] >= pH->array[child]){
			return;
		}

		Swap(pH->array + parent, pH->array + child);
		child = parent;
	}
}

/*
插入
*/
void HeapPush(Heap *pH, int data)
{
	assert(pH->size < 100);
	pH->array[pH->size++] = data;
	HeapAdjustUp(pH, pH->size - 1);
}

void ArrayAdjustDown(int array[], int size, int root)
{
	int parent = root;

	while (1) {
		// 先判断有没有孩子（叶子结点）
		// 数组角度去想	-> 孩子的下标是否越界
		// 只要判断左孩子的下标（因为是完全二叉树)
		int left = parent * 2 + 1;
		if (left >= size) {
			// 越界，没有左孩子，也肯定没有右孩子
			return;
		}

		// 一定有左孩子
		int maxChild = left;
		if (2 * parent + 2 < size && array[2 * parent + 2] > array[left]) {
			// 前一个条件是判断右孩子有没有
			// 后一个条件判读是右孩子是否比左孩子大
			maxChild = 2 * parent + 2;
		}

		if (array[parent] > array[maxChild]) {
			return;
		}

		// 交换 root 和 maxChild 下标所在的值
		int t = array[parent];
		array[parent] = array[maxChild];
		array[maxChild] = t;

		parent = maxChild;
	}
}

/*
选择排序
*/
//一次找到未排序空间的最大值，交换最大值到空间（堆可以找到最值）
// 堆排序（升序）
// 时间复杂度 O(n * Logn)
// 空间复杂度 O(1)
void HeapSort(int array[], int size)
{
	//建大堆（在原有数组上建堆）
	for (int i = (size - 2) / 2; i >= 0; i--){
		ArrayAdjustDown(array, size, i);
	}

	//开始排序
	for (int j = 0; j < size; j++){
		//位置
		int s = size - 1 - j;
		Swap(array, array + s);
		ArrayAdjustDown(array, size - 1 - j, 0);
	}
}

// TopK	找最小的 k 个数据，需要建大堆
// 和排序不太一样：排序是在原数组调整。TopK 最好不要在原数组上调整
int *TopK(int array[], int size, int k)
{
	int *heapArray = (int *)malloc(k * sizeof(int));
	assert(heapArray);

	//搬前 k 个数过去
	for (int i = 0; i < k; i++){
		heapArray[i] = array[i];
	}

	//建堆，建大堆
	//这里的 size 其实是 k
	for (int j = (k - 2) / 2; j >= 0; j--){
		ArrayAdjustDown(heapArray, k, j);
	}

	for (int m = k; m < size; m++){
		if (array[m] >= heapArray[0]){
			continue;
		}

		heapArray[0] = array[m];
		ArrayAdjustDown(heapArray, k, 0);
		// 不要用  Swap(heapArray, array + m);
	}
	return heapArray;
}