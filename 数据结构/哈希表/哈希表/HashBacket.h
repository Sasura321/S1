/*
**��ɢ�� ����ϣͰ��
*/
#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int Key;

typedef struct Node {
	Key	key;
	struct Node *next;
}	Node;

typedef struct {
	int	size;
	int capacity;
	Node * * array;
}	HashBucket;

void HashBucketInit(HashBucket *pHB, int capacity)
{
	pHB->array = (Node **)malloc(sizeof(Node *)* capacity);
	pHB->size = 0;
	pHB->capacity = capacity;

	for (int i = 0; i < capacity; i++) {
		pHB->array[i] = NULL;
	}
}

void ListDestroy(Node * first)
{
	Node *next;
	for (Node * cur = first; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}
}

void HashBucketDestroy(HashBucket *pHB)
{
	// ��Ҫ���ͷ� ��ϣͰ ����
	for (int i = 0; i < pHB->capacity; i++) {
		ListDestroy(pHB->array[i]);
	}

	// ���ͷŹ�ϣͰ
	free(pHB->array);
}

// ����
// �ҵ��������ڽ���ַ
// û�ҵ����� NULL
Node * HashBucketSearch(HashBucket *pHB, Key key)
{
	int index = key % pHB->capacity;
	Node *cur = pHB->array[index];
	while (cur != NULL) {
		if (cur->key == key) {
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

int HashBucketInsert(HashBucket *pHB, Key key);

void ExpandIfRequired(HashBucket *pHB)
{
	if (pHB->size < pHB->capacity) {
		return;
	}

	HashBucket newHB;
	HashBucketInit(&newHB, pHB->capacity * 2);

	for (int i = 0; i < pHB->capacity; i++) {
		for (Node * cur = pHB->array[i]; cur != NULL; cur = cur->next) {
			HashBucketInsert(&newHB, cur->key);
		}
	}

	HashBucketDestroy(pHB);

	pHB->array = newHB.array;
	pHB->capacity = newHB.capacity;
}

// ����	���Ϳ��ŵ�ַ��ͬ��û�и������ӵĸ��� 1��
// �ɹ����� 0��ʧ�ܷ��� -1
int HashBucketInsert(HashBucket *pHB, Key key)
{
	ExpandIfRequired(pHB);

	if (HashBucketSearch(pHB, key) != NULL) {
		return -1;
	}

	int index = key % pHB->capacity;
	Node * first = pHB->array[index];
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->key = key;
	newNode->next = NULL;

	// ͷ��
	newNode->next = first;
	pHB->array[index] = newNode;
	pHB->size++;

	return 0;
}

// ɾ��
int HashBucketRemove(HashBucket *pHB, Key key)
{
	int index = key % pHB->capacity;
	Node *prev = NULL;
	for (Node *cur = pHB->array[index]; cur != NULL; cur = cur->next) {
		if (cur->key == key) {
			// ɾ��
			if (prev == NULL) {
				// ���Ҫɾ���Ľ���ǵ�һ�����
				pHB->array[index] = cur->next;
			}
			else {
				prev->next = cur->next;
			}
			free(cur);

			pHB->size--;
			return 0;
		}

		prev = cur;
	}

	return -1;
}

int PXCHash(const char *str)
{
	unsigned int hash = 0;
	while (*str) {
		hash += *str++;
	}

	return hash & 0x7FFFFFFF;
}

unsigned int KBDR(const char *str)
{
	unsigned int seed = 131;
	unsigned int hash = 0;

	while (*str) {
		hash = hash * seed + (*str++);
	}

	return hash & 0x7FFFFFFF;
}

void Test2()
{
	HashBucket hb;
	HashBucketInit(&hb, 10);

	printf("%d\n", KBDR("apple"));
	printf("%d\n", KBDR("pplea"));
	printf("%d\n", KBDR("pleap"));
	printf("\n");

	printf("%d\n", PXCHash("apple"));
	printf("%d\n", PXCHash("pplea"));
	printf("%d\n", PXCHash("pleap"));

	/*
	for (int i = 0; i < 100; i++) {
		HashBucketInsert(&hb, 0 + i * 10);
	}

	printf("%p\n", HashBucketSearch(&hb, 20));
	HashBucketRemove(&hb, 20);
	printf("%p\n", HashBucketSearch(&hb, 20));
	*/
}