#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int Key;

typedef enum {
	EMPTY,   // 空的
	EXIST,   // 有数据的
	DELETED  // 被删除的
}	State;

typedef struct Elenent {
	Key key;
	State state;
}	Element;

typedef int(*HashFuncType) (Key key, int capacity);

typedef struct HashTable {
	Element *table;
	int size;        // 数据个数
	int capacity;    // 容量
	HashFuncType hashFunc;    //哈希函数
}	HashTable;

//初始化
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

//销毁
void HashDestroy(HashTable *pHT)
{
	free(pHT->table);
}

//查找  [Find / Search / Query]
//线性探测法
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

		//如果哈希表存满了，是个死循环
		//但哈希表不会被存满
		//二次探测法变换的位置
		index = (o_index + 1) % pHT->capacity;
		i++;
	}

	//没找到
	return 0;
}

