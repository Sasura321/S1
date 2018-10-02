#pragma once

#include <stdlib.h>
#include <assert.h>

typedef int DataType;

#define INIT_CAPACITY (3)

typedef struct SeqListD{
	DataType *parray;
	int capacity;	// 当前容量 等于 静态顺序表 MAX_SIZE
	int size;		// 同静态顺序表
}	SeqListD;

// 初始化/销毁/所有插入（尾插）
// 其他和静态顺序表完全一样

//初始化
void SeqListDInit(SeqListD *pSeq)
{
	//为了获得容量空间
	pSeq->capacity = INIT_CAPACITY;
	pSeq->parray = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
	assert(pSeq->parray);

	//这个和顺序表一样
	pSeq->size = 0;
}

//销毁
void SeqListDDestroy(SeqListD *pSeq)
{
	free(pSeq->parray);

	pSeq->capacity = 0;
	pSeq->parray = NULL;
	pSeq->size = 0;
}

// 头插
static void ExpandIfRequired(SeqListD *pSeq);
void SeqListDPushBack(SeqListD *pSeq, DataType data)
{
	//动态线性表，如果满了则加入扩容机制
	ExpandIfRequired(pSeq);

	pSeq->parray[pSeq->size] = data;
	pSeq->size++;
}

static void ExpandIfRequired(SeqListD *pSeq)
{
	//扩容条件
	if (pSeq->size < pSeq->capacity)
	{
		return ;
	}

	// 扩容
	pSeq->capacity *= 2;

	// 1.申请新空间
	DataType *newArray = (DataType *)malloc(sizeof(DataType)* pSeq->capacity);
	assert(newArray);
	// 2.数据搬移
	for (int i = 0; i < pSeq->size; i++)
	{
		newArray[i] = pSeq->parray[i];
	}
	// 3.释放老空间，关联老空间
	free(pSeq->parray);
	pSeq->parray = newArray;
}

void Test()
{
	SeqListD sld;
	SeqListDInit(&sld);

	SeqListDPushBack(&sld, 1);
	SeqListDPushBack(&sld, 2);
	SeqListDPushBack(&sld, 3);
	//  这下面会扩容
	SeqListDPushBack(&sld, 4);
	SeqListDPushBack(&sld, 5);
}