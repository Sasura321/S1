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

typedef int (*HashFuncType) (Key key, int capacity);

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
	int index = pHT->hashFunc(key, pHT->capacity);
	while (pHT->table[index].state == EXIST){
		if (pHT->table[index].key == key
			&&pHT->table[index].state == EXIST){
			return index;
		}

		//如果哈希表存满了，是个死循环
		//但哈希表不会被存满

#if 0
		//方法1
		index = index + 1;
		if (index == pHT->capacity){
			index = 0;
		}

#else
		//方法2
		index = (index + 1) % pHT->capacity;
#endif
	}

	//没找到
	return 0;
}


int HashInsert(HashTable *pHT, Key key);

//扩容
void ExpandIfRequired(HashTable *pHT)
{
	//不扩容
	if (pHT->size * 10 / pHT->capacity < 7){
		return;
	}

//数据搬移太麻烦了，不要了
#if 0
	int newCapacity = pHT->capacity * 2;
	Element *newTable = (Element *)malloc(sizeof(Element)*newCapacity);
	assert(newTable);

	// newTable 的状态都更新成 EMPTY
	for (int i = 0; i < newCapacity; i++){
		newTable[i].state = EMPTY;
	}

	// 老的数据迁移过来
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

//插入
//Key 不允许重复
//0 插入成功，-1 插入失败
int HashInsert(HashTable *pHT, Key key)
{
	//扩容
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

//删除
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

//哈希函数(除留余数法)
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