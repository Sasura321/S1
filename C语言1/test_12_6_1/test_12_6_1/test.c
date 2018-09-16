//有一个顺序表L，假设元素类型ElemType为整数
//设计一个尽可能高级的算法，将所有奇数移到偶数的前面

#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10

typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

void InitList_Sq(SqList &L)  //构造一个线性表
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	int i = 0;
	for(i = 0;i < 10;i++)
		L.elem[i] = rand()%100;
	L.length = 10;
	L.listsize = LIST_INIT_SIZE;//初始储存容量
}InitList_Sq

void MoveList(SqList &L)
{
	int i = 0;
	int j = L.length-1;
	int temp = 0;
	while(i<j)
	{
		if((L.elem[i]%2) == 0)
		{
			temp = L.elem[i];
		}
		else
		{
			i++;
		}
		if((L.elem[j]%2) != 0)
		{
			L.elem[i] = L.elem[j];
			L.elem[j] = temp;
		}
		else
		{
			j--;
		}
	}
}

void DisList(SqlList L)  //输出
{
	int i = 0;
 while(L.elem[i])
 {
	 printf("%n",L.elem[i]);
	 i++;
 }

int main()
{
	Sqlist L;
	InitList_Sq(L)
	MoveList(L);
	DisList(L);
	return 0 ;
}