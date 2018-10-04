#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned char uint32_t;

typedef struct {
	uint32_t *array;
	unsigned int size;      //�ж���������Ϣ
	unsigned int capacity;  // array ������
}	BitArray;

void BitArrayInit(BitArray *pBA)
{
	// (unsigned int )-1 ���� 2^32-1
	// ������Ǵ���ֵ��û�е� 2^32 / 32
	unsigned int capacity = (unsigned int)-1 / 32;
	pBA->capacity = capacity;
	pBA->array = (uint32_t *)malloc(sizeof(uint32_t)*capacity);
	memset(pBA->array, 0, sizeof(uint32_t)*capacity);
	pBA->size = 0;
}

// �� n ����λ�� bit ��Ϊ 1
void BitArrayOne(BitArray *pBA, unsigned int n)
{
	unsigned int index = n / 32;
	unsigned int bit = n % 32;

	pBA->array[index] |= (1UL << bit);
}

// �� n ����λ�� bit ��Ϊ 0
void BitArrayZero(BitArray *pBA, unsigned int n)
{
	unsigned int index = n / 32;
	unsigned int bit = n % 32;

	pBA->array[index] &= ~(1UL << bit);
}

// ���� n ���� bit �Ƿ�Ϊ1
// �Ƿ��� ��0�����Ƿ��� 0
int BitArrayIsOne(BitArray *pBA, unsigned int n)
{
	unsigned int index = n / 32;
	unsigned int bit = n % 32;

	return pBA->array[index] & (1UL << bit);
}

void Test3()
{
	BitArray ba;
	BitArrayInit(&ba);

	srand(20180910);
	for (int i = 0; i < 200; i++){
		unsigned int n = rand();
		BitArrayOne(&ba, n);
	}

	printf("%d\n", BitArrayIsOne(&ba,350));
}