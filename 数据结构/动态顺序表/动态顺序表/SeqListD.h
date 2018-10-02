#pragma once

#include <stdlib.h>
#include <assert.h>

typedef int DataType;

#define INIT_CAPACITY (3)

typedef struct SeqListD{
	DataType *parray;
	int capacity;	// ��ǰ���� ���� ��̬˳��� MAX_SIZE
	int size;		// ͬ��̬˳���
}	SeqListD;

// ��ʼ��/����/���в��루β�壩
// �����;�̬˳�����ȫһ��

//��ʼ��
void SeqListDInit(SeqListD *pSeq)
{
	//Ϊ�˻�������ռ�
	pSeq->capacity = INIT_CAPACITY;
	pSeq->parray = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
	assert(pSeq->parray);

	//�����˳���һ��
	pSeq->size = 0;
}

//����
void SeqListDDestroy(SeqListD *pSeq)
{
	free(pSeq->parray);

	pSeq->capacity = 0;
	pSeq->parray = NULL;
	pSeq->size = 0;
}

// ͷ��
static void ExpandIfRequired(SeqListD *pSeq);
void SeqListDPushBack(SeqListD *pSeq, DataType data)
{
	//��̬���Ա����������������ݻ���
	ExpandIfRequired(pSeq);

	pSeq->parray[pSeq->size] = data;
	pSeq->size++;
}

static void ExpandIfRequired(SeqListD *pSeq)
{
	//��������
	if (pSeq->size < pSeq->capacity)
	{
		return ;
	}

	// ����
	pSeq->capacity *= 2;

	// 1.�����¿ռ�
	DataType *newArray = (DataType *)malloc(sizeof(DataType)* pSeq->capacity);
	assert(newArray);
	// 2.���ݰ���
	for (int i = 0; i < pSeq->size; i++)
	{
		newArray[i] = pSeq->parray[i];
	}
	// 3.�ͷ��Ͽռ䣬�����Ͽռ�
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
	//  �����������
	SeqListDPushBack(&sld, 4);
	SeqListDPushBack(&sld, 5);
}