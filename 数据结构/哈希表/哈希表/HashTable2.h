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

typedef int(*HashFuncType) (Key key, int capacity);

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
	int o_index = pHT->hashFunc(key, pHT->capacity);
	int index = o_index;
	int i = 1;

	while (pHT->table[o_index].state == EXIST){
		if (pHT->table[o_index].key == key
			&&pHT->table[o_index].state == EXIST){
			return index;
		}

		//�����ϣ������ˣ��Ǹ���ѭ��
		//����ϣ���ᱻ����
		//����̽�ⷨ�任��λ��
		index = (o_index + 1) % pHT->capacity;
		i++;
	}

	//û�ҵ�
	return 0;
}

