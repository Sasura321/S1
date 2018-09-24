#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

#define MAX_SIZE (100)

typedef struct SeqList{
	DataType array[MAX_SIZE];
	int size;   // 1. ����˳������Ѿ����˵����ݸ���
	// 2. ��ǰ�����±�
}	SeqList;

//typedef struct SeqList SeqList

// �ӿڣ�������
// ��ʼ��/����
// ��/ɾ/��/�ģ�д��

//��ʼ����������ƣ�
void SeqListInit(SeqList *pSeq)
{
	//1.��ʼ�� size
	//2.������Ҫȥ�������ռ������

	assert(pSeq != NULL);
	pSeq->size = 0;
	//memset(pSeq->array, 0, MAX_SIZE * sizeof(DataType));
}

//����
void SeqListDestroy(SeqList *pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}

//��
//β�壨������ C++ �� STL ͳһ��
void SeqListPushBack(SeqList *pSeq, DataType data)
{
	assert(pSeq);

	//������������ˣ�
	if (pSeq->size >= MAX_SIZE){
		printf("���ˣ�\n");
		assert(0);
		return;
	}

	//�������
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//ͷ��
void SeqListPushFront(SeqList *pSeq, DataType data)
{
	assert(pSeq);

	//������������ˣ�
	if (pSeq->size >= MAX_SIZE){
		printf("���ˣ�\n");
		assert(0);
		return;
	}

	//�������
	//�����������������һ��
	for (int i = pSeq->size; i > 0; i--) {
		// ǰ����λ��  ����������
		pSeq->array[i] = pSeq->array[i - 1];
	}

	// i �����������
	/*
	for (int i = pSeq->size - 1; i >= 0; i--) {
	pSeq->array[i + 1] = pSeq->array[i];
	}
	*/

	//����
	pSeq->array[0] = data;
	pSeq->size++;
}

//�м����
void SeqListInsert(SeqList *pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	//������������ˣ�
	if (pSeq->size >= MAX_SIZE){
		printf("���ˣ�\n");
		assert(0);
		return;
	}

	//�������
	// 1. ���ݰ���
	// 1) �Ӻ���ǰ 2) i ȡ ���� [size - 1, pos]
	for (int i = pSeq->size - 1; i >= pos; i--){
		pSeq->array[i + 1] = pSeq->array[i];
	}

	// 2. ����
	pSeq->array[pos] = data;
	pSeq->size++;
}

//ɾ
//βɾ
void SeqListPopBack(SeqList *pSeq)
{
	assert(pSeq);

	//������������ˣ�
	if (pSeq->size <= 0){
		printf("���ˣ�\n");
		assert(0);
		return;
	}

	//�������
	pSeq->size--;
}

//ͷɾ
void SeqListPopFront(SeqList *pSeq)
{
	assert(pSeq);

	//������������ˣ�
	if (pSeq->size <= 0){
		printf("����\n");
		assert(0);
		return;
	}

	//ͨ�����
	for (int i = 0; i < pSeq->size; i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}

	pSeq->size--;
}

//�м�ɾ
void SeqListErase(SeqList *pSeq, int pos)
{
	assert(pSeq);
	assert(pos >= 0 && pos < pSeq->size);

	// ������������ˣ�
	if (pSeq->size <= 0){
		printf("���ˣ�\n");
		assert(0);
		return;
	}

	// ���ݰ���
	// 1) ��ǰ���� 2) i ȡλ��
	for (int i = pos; i <= pSeq->size - 2; i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}

	pSeq->size--;
}

//��ӡ
// ��ָ����ٿռ䣬���ı�ֵ
void SeqListPrint(const SeqList *pSeq)
{
	assert(pSeq != NULL);

	for (int i = 0; i < pSeq->size; i++){
		printf("%d  ", pSeq->array[i]);
	}
	printf("\n");
}



// ����
// �ҵ���һ�������������±꣬û�ҵ����� -1 (�����뷵������ ssize_t)
int SeqListFind(SeqList *pSeq, DataType data)
{
	// ����������գ�
	if (pSeq->size <= 0) {
		printf("��\n");
		assert(0);
		return -1;
	}

	//˳���������
	for(int i = 0; i < pSeq->size; i++){
		if (data == pSeq->array[i]){
			//�����±�
			return i;
		}
	}

	//û�ҵ�
	return -1;
}

// ���ң�����2��
int SeqListFind2(SeqList *pSeq, DataType data)
{
	// ����������գ�
	if (pSeq->size <= 0) {
		printf("��\n");
		assert(0);
		return -1;
	}

	//���ֲ��ң�ǰ�᣺����
	int left = 0;
	int right = pSeq->size;
	int mid = 0;
	while (right>=left){
		mid = (left + right) / 2;
		if (data == pSeq->array[mid]) {
			// �ҵ������±�
			return mid;
		}
		else if (data > pSeq->array[mid]){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}

	//û�ҵ�
	if (right < left){
		return -1;
	}
}

// ɾ���ڶ�����̬ (��������ɾ��)
// 1. ɾ�����ĵ�һ������
void SeqListRemove(SeqList *pSeq, DataType data)
{
	int pos = SeqListFind(pSeq, data);
	if (pos == -1){
		//û�ҵ�
		return;
	}

	SeqListErase(pSeq, pos);
}

//2.ɾ��������������
//(1).
void SeqListRemoveAll1(SeqList *pSeq, DataType data)
{
	int pos = 0;
	while ((pos = SeqListFind(pSeq, data)) != -1){
		SeqListErase(pSeq, pos);
	}
}

// (2). һ�α���ɾ��
// �ô�: һ�α�����ʱ��ȽϿ�
// ����: �����¿ռ䣬�ռ��С�� size �й�ϵ
// 1) ��������
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

	//�����ݰ����
	for (i = 0; i < j; i++){
		pSeq->array[i] = newArray[i];
	}
	pSeq->size = j;

	//�ͷ�
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