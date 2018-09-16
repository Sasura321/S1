//有一个顺序表L，假设元素类型ElemType为整数
//设计一个尽可能高级的算法，将所有奇数移到偶数的前面

#include <stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10

typedef int  ElemType;
typedef  struct 
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

void InitList(SqList &L,int arr[])  //构造一个线性表
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	int i = 0;
	L.length = 0;
	for (i = 0; i < 8; i++)
	{
		L.elem[i] = arr[i];
	    L.length++;
	}
	L.listsize = LIST_INIT_SIZE;//初始储存容量
}

void MoveList(SqList &L)
{
    int i = 0;
    int j = L.length-1;
    int pivot=L.elem[0];
    while(i<j)
   { 
	   while(i<j&&L.elem[j]%2 == 1)
		   j--;
	   L.elem[i]=L.elem[j];
	   while(i<j&&L.elem[i]%2 == 0)
		   i++;
	   L.elem[j]=L.elem[i];
	}
	L.elem[i]=pivot;
}



void DisList(SqList L)  //输出
{
	int i = 0;
	for(i = 0;i<L.length;i++)
		printf("%d", L.elem[i]);
	printf("\n");

}
int main()
{
	SqList L;
	int arr[] = {1,2,3,4,5,6,7,8};
	InitList(L,arr);
	MoveList(L);
	DisList(L);
	return 0;
}
