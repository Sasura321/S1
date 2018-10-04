#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int Key;

typedef enum {
	EMPTY,   // �յ�
	EXIST,   // �����ݵ�
	DELETED  // ��ɾ����
}	State;

typedef struct Elenent {
	Key key;
	State state;
}	Element;

typedef int (*HashFuncType) (Key key, int capacity);

typedef struct HashTable {
	Element *table;
	int size;        // ���ݸ���
	int capacity;    // ����
	HashFuncType hashFunc;    //��ϣ����
}	HashTable;

//��ʼ��
void HashInit(HashTable *pHT, int capacity, HashFuncType hashFunc)
{
	pHT->table = (Element *)malloc(sizeof(Element)*capacity);
	assert(pHT->table);

	pHT->size = 0;
	pHT->capacity = capacity;
	pHT->hashFunc = hashFunc;

	for (int i = 0; i < capacity; i++){
		pHT->table[i].state = EMPTY;
	}
}

//����
void HashDestroy(HashTable *pHT)
{
	free(pHT->table);
}

//����  [Find / Search / Query]
//����̽�ⷨ
int HashSearch(HashTable *pHT, Key key)
{
	int index = pHT->hashFunc(key, pHT->capacity);
	while (pHT->table[index].state == EXIST){
		if (pHT->table[index].key == key
			&&pHT->table[index].state == EXIST){
			return index;
		}

		//�����ϣ������ˣ��Ǹ���ѭ��
		//����ϣ���ᱻ����

#if 0
		//����1
		index = index + 1;
		if (index == pHT->capacity){
			index = 0;
		}

#else
		//����2
		index = (index + 1) % pHT->capacity;
#endif
	}

	//û�ҵ�
	return 0;
}


int HashInsert(HashTable *pHT, Key key);

//����
void ExpandIfRequired(HashTable *pHT)
{
	//������
	if (pHT->size * 10 / pHT->capacity < 7){
		return;
	}

//���ݰ���̫�鷳�ˣ���Ҫ��
#if 0
	int newCapacity = pHT->capacity * 2;
	Element *newTable = (Element *)malloc(sizeof(Element)*newCapacity);
	assert(newTable);

	// newTable ��״̬�����³� EMPTY
	for (int i = 0; i < newCapacity; i++){
		newTable[i].state = EMPTY;
	}

	// �ϵ�����Ǩ�ƹ���
	free(pHT->table);
	pHT->table = newTable;
	pHT->capacity = newCapacity;
#endif

	HashTable newHT;
	HashInit(&newHT, pHT->capacity * 2, pHT->hashFunc);
	for (int i = 0; i < pHT->capacity; i++){
		if (pHT->table[i].state == EXIST){
			HashInsert(&newHT, pHT->table[i].key);
		}
	}

	free(pHT->table);
	pHT->table = newHT.table;
	pHT->capacity = newHT.capacity;
}

//����
//Key �������ظ�
//0 ����ɹ���-1 ����ʧ��
int HashInsert(HashTable *pHT, Key key)
{
	//����
	ExpandIfRequired(pHT);

	int index = pHT->hashFunc(key, pHT->capacity);
	while (1){
		if (pHT->table[index].key == key
			&& pHT->table[index].state == EXIST){
			return -1;
		}

		if (pHT->table[index].state != EXIST){
			pHT->table[index].key = key;
			pHT->table[index].state = EXIST;
			pHT->size++;
			return 0;
		}

		index = (index + 1) % pHT->capacity;
	}
}

//ɾ��
void HashRemove(HashTable *pHT, Key key)
{
	int index = pHT->hashFunc(key, pHT->capacity);
	while (pHT->table[index].state != EMPTY){
		if (pHT->table[index].key == key
			&& pHT->table[index].state == EXIST){
			pHT->table[index].state = DELETED;
			return;
		}
		index = (index + 1) % pHT->capacity;
	}
}

//��ϣ����(����������)
int mod(Key key, int capacity)
{
	return key % capacity;
}

void Test1()
{
	HashTable ht;
	HashInit(&ht, 10, mod);

	HashInsert(&ht, 1);
	HashInsert(&ht, 21);
	HashInsert(&ht, 31);
	HashInsert(&ht, 41);
	HashInsert(&ht, 51);
	HashInsert(&ht, 61);
	HashInsert(&ht, 71);

	printf("%d\n", HashSearch(&ht, 21));
	HashRemove(&ht, 1);
	printf("%d\n", HashSearch(&ht, 21));

	HashDestroy(&ht);
}