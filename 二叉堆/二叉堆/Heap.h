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
��ʼ��
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
���µ���
*/
void HeapAdjustDown(Heap *pH, int root)
{
	int parent = root;

	while (1){
		//���ж���û�к��ӣ�Ҷ�ӽ�㣩
		// ����Ƕ�ȥ��	-> ���ӵ��±��Ƿ�Խ��
		// ֻҪ�ж����ӵ��±꣨��Ϊ����ȫ������)
		int left = parent * 2 + 1;
		int right = parent * 2 + 2;
		//�ж��Ƿ�Խ��
		// Խ�磬û�����ӣ�Ҳ�϶�û���Һ���x
		while (left > pH->size){
			return;
		}

		//һ��������
		int maxChild = left;
		while ((right > pH->size) && (pH->array[right] > pH->array[left])){
			//�ж��Ƿ����Һ��ӣ������ж��Һ����Ƿ��������
			maxChild = right;
		}
		if (pH->array[parent] > pH->array[maxChild]){
			return;
		}

		// ���� root �� maxChild �±����ڵ�ֵ
		int temp = pH->array[parent];
		pH->array[parent] = pH->array[maxChild];
		pH->array[maxChild] = temp;

		parent = maxChild;
	}
}

// 1. �����Խ���жϲ��ԣ� �Ƿ� == size
// 2. array[left] == NULL	array -> int[]	��ô�ж������ڲ����Ǵ��
// 3. ������ʱ�򣬽������±꣬�������±����ڵ�ֵ
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
	//left ������
}

/*
����
*/
void HeapMakeHeap(Heap *pH)
{
	//[(size-2)/2,2]   (����ȡ��)
	//���һ��Ҷ�ӽ��size-1�����һ����Ҷ�ӽ��((size-1)-1)/2
	for (int i = (pH->size - 2) / 2; i >= 0; i--){
		HeapAdjustDown(pH, i);
	}
}

/*
ɾ��
*/
//ɾ����ȡ���һ�����ݣ�size-1��,�� 0����λ�õ����ݽ�����
//Ȼ��������µ�����ɾ��ֻ��ɾ��ջ��Ԫ�أ�
void HeapPop(Heap *pH)
{
	pH->array[0] = pH->array[pH->size - 1];
	pH->size--;

	HeapAdjustDown(pH, 0);
}

/*
ȡջ��Ԫ��
*/
int HeapTop(const Heap *pH)
{
	return pH->array[0];
}

/*
���ϵ���
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
����
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
		// ���ж���û�к��ӣ�Ҷ�ӽ�㣩
		// ����Ƕ�ȥ��	-> ���ӵ��±��Ƿ�Խ��
		// ֻҪ�ж����ӵ��±꣨��Ϊ����ȫ������)
		int left = parent * 2 + 1;
		if (left >= size) {
			// Խ�磬û�����ӣ�Ҳ�϶�û���Һ���
			return;
		}

		// һ��������
		int maxChild = left;
		if (2 * parent + 2 < size && array[2 * parent + 2] > array[left]) {
			// ǰһ���������ж��Һ�����û��
			// ��һ�������ж����Һ����Ƿ�����Ӵ�
			maxChild = 2 * parent + 2;
		}

		if (array[parent] > array[maxChild]) {
			return;
		}

		// ���� root �� maxChild �±����ڵ�ֵ
		int t = array[parent];
		array[parent] = array[maxChild];
		array[maxChild] = t;

		parent = maxChild;
	}
}

/*
ѡ������
*/
//һ���ҵ�δ����ռ�����ֵ���������ֵ���ռ䣨�ѿ����ҵ���ֵ��
// ����������
// ʱ�临�Ӷ� O(n * Logn)
// �ռ临�Ӷ� O(1)
void HeapSort(int array[], int size)
{
	//����ѣ���ԭ�������Ͻ��ѣ�
	for (int i = (size - 2) / 2; i >= 0; i--){
		ArrayAdjustDown(array, size, i);
	}

	//��ʼ����
	for (int j = 0; j < size; j++){
		//λ��
		int s = size - 1 - j;
		Swap(array, array + s);
		ArrayAdjustDown(array, size - 1 - j, 0);
	}
}

// TopK	����С�� k �����ݣ���Ҫ�����
// ������̫һ������������ԭ���������TopK ��ò�Ҫ��ԭ�����ϵ���
int *TopK(int array[], int size, int k)
{
	int *heapArray = (int *)malloc(k * sizeof(int));
	assert(heapArray);

	//��ǰ k ������ȥ
	for (int i = 0; i < k; i++){
		heapArray[i] = array[i];
	}

	//���ѣ������
	//����� size ��ʵ�� k
	for (int j = (k - 2) / 2; j >= 0; j--){
		ArrayAdjustDown(heapArray, k, j);
	}

	for (int m = k; m < size; m++){
		if (array[m] >= heapArray[0]){
			continue;
		}

		heapArray[0] = array[m];
		ArrayAdjustDown(heapArray, k, 0);
		// ��Ҫ��  Swap(heapArray, array + m);
	}
	return heapArray;
}