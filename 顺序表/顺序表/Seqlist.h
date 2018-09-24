#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

#define MAX_SIZE (100)

typedef struct SeqList{
	DataType array[MAX_SIZE];
	int size;   // 1. 保存顺序表里已经存了的数据个数
	// 2. 当前可用下标
}	SeqList;

//typedef struct SeqList SeqList

// 接口（函数）
// 初始化/销毁
// 增/删/查/改（写）

//初始化（函数设计）
void SeqListInit(SeqList *pSeq)
{
	//1.初始化 size
	//2.可能需要去把容器空间清空下

	assert(pSeq != NULL);
	pSeq->size = 0;
	//memset(pSeq->array, 0, MAX_SIZE * sizeof(DataType));
}

//销毁
void SeqListDestroy(SeqList *pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}

//增
//尾插（尽量和 C++ 的 STL 统一）
void SeqListPushBack(SeqList *pSeq, DataType data)
{
	assert(pSeq);

	//特殊情况（满了）
	if (pSeq->size >= MAX_SIZE){
		printf("满了！\n");
		assert(0);
		return;
	}

	//正常情况
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//头插
void SeqListPushFront(SeqList *pSeq, DataType data)
{
	assert(pSeq);

	//特殊情况（满了）
	if (pSeq->size >= MAX_SIZE){
		printf("满了！\n");
		assert(0);
		return;
	}

	//正常情况
	//现有数据整体往后搬一格
	for (int i = pSeq->size; i > 0; i--) {
		// 前面是位置  后面是数据
		pSeq->array[i] = pSeq->array[i - 1];
	}

	// i 代表的是数据
	/*
	for (int i = pSeq->size - 1; i >= 0; i--) {
	pSeq->array[i + 1] = pSeq->array[i];
	}
	*/

	//插入
	pSeq->array[0] = data;
	pSeq->size++;
}

//中间插入
void SeqListInsert(SeqList *pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	//特殊情况（满了）
	if (pSeq->size >= MAX_SIZE){
		printf("满了！\n");
		assert(0);
		return;
	}

	//正常情况
	// 1. 数据搬移
	// 1) 从后往前 2) i 取 数据 [size - 1, pos]
	for (int i = pSeq->size - 1; i >= pos; i--){
		pSeq->array[i + 1] = pSeq->array[i];
	}

	// 2. 插入
	pSeq->array[pos] = data;
	pSeq->size++;
}

//删
//尾删
void SeqListPopBack(SeqList *pSeq)
{
	assert(pSeq);

	//特殊情况（空了）
	if (pSeq->size <= 0){
		printf("空了！\n");
		assert(0);
		return;
	}

	//正常情况
	pSeq->size--;
}

//头删
void SeqListPopFront(SeqList *pSeq)
{
	assert(pSeq);

	//特殊情况（空了）
	if (pSeq->size <= 0){
		printf("空了\n");
		assert(0);
		return;
	}

	//通常情况
	for (int i = 0; i < pSeq->size; i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}

	pSeq->size--;
}

//中间删
void SeqListErase(SeqList *pSeq, int pos)
{
	assert(pSeq);
	assert(pos >= 0 && pos < pSeq->size);

	// 特殊情况（空了）
	if (pSeq->size <= 0){
		printf("空了！\n");
		assert(0);
		return;
	}

	// 数据搬移
	// 1) 从前往后 2) i 取位置
	for (int i = pos; i <= pSeq->size - 2; i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}

	pSeq->size--;
}

//打印
// 传指针减少空间，不改变值
void SeqListPrint(const SeqList *pSeq)
{
	assert(pSeq != NULL);

	for (int i = 0; i < pSeq->size; i++){
		printf("%d  ", pSeq->array[i]);
	}
	printf("\n");
}



// 查找
// 找到第一个遇到的数的下标，没找到返回 -1 (更理想返回类型 ssize_t)
int SeqListFind(SeqList *pSeq, DataType data)
{
	// 特殊情况（空）
	if (pSeq->size <= 0) {
		printf("空\n");
		assert(0);
		return -1;
	}

	//顺序遍历查找
	for(int i = 0; i < pSeq->size; i++){
		if (data == pSeq->array[i]){
			//返回下标
			return i;
		}
	}

	//没找到
	return -1;
}

// 查找（方法2）
int SeqListFind2(SeqList *pSeq, DataType data)
{
	// 特殊情况（空）
	if (pSeq->size <= 0) {
		printf("空\n");
		assert(0);
		return -1;
	}

	//二分查找（前提：有序）
	int left = 0;
	int right = pSeq->size;
	int mid = 0;
	while (right>=left){
		mid = (left + right) / 2;
		if (data == pSeq->array[mid]) {
			// 找到返回下标
			return mid;
		}
		else if (data > pSeq->array[mid]){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}

	//没找到
	if (right < left){
		return -1;
	}
}

// 删除第二种形态 (根据数据删除)
// 1. 删遇到的第一个数据
void SeqListRemove(SeqList *pSeq, DataType data)
{
	int pos = SeqListFind(pSeq, data);
	if (pos == -1){
		//没找到
		return;
	}

	SeqListErase(pSeq, pos);
}

//2.删遇到的所有数据
//(1).
void SeqListRemoveAll1(SeqList *pSeq, DataType data)
{
	int pos = 0;
	while ((pos = SeqListFind(pSeq, data)) != -1){
		SeqListErase(pSeq, pos);
	}
}

// (2). 一次遍历删除
// 好处: 一次遍历，时间比较快
// 坏处: 开了新空间，空间大小和 size 有关系
// 1) 开新数组
void SeqListRemoveAll2(SeqList *pSeq, DataType data)
{
	DataType *newArray = (DataType*)malloc(sizeof(DataType)*pSeq->size);
	int i, j;
	for (i = 0, j = 0; i < pSeq->size; i++){
		if (data != pSeq->array[i]){
			newArray[j] = pSeq->array[i];
			j++;
		}
	}

	//把数据搬回来
	for (i = 0; i < j; i++){
		pSeq->array[i] = newArray[i];
	}
	pSeq->size = j;

	//释放
	free(newArray);
}

void SeqListRemoveAll3(SeqList *pSeq, DataType data)
{
	int i, j;
	for (i = 0, j = 0; i < pSeq->size; i++){
		if (data != pSeq->array[i]){
			pSeq->array[j] = pSeq->array[i];
			j++;
		}
	}
	pSeq->size = j;
}