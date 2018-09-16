#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define LIST_INIT_SIZE  100  //线性表存储空间的初始分配量
 
typedef struct
{
	int *elem;   //存储空间基址
	int R[MAXSIZE+1];
	int length;
}Sqlist;

void CreateList(SqList &L,int R[]) 
//引用一个一维数组arr[]构造一个线性表L
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	int i = 0;
	L.length = 0;
	for (i = 0; i < 10; i++)
	{
		L.elem[i] = R[i];  //引用数组arr[]
	    L.length++;          //得到顺序表L的长度
	}
	
}

void Quicksort(Sqlist &L,int i,int j)
//将比枢轴temp小的元素放到左边，大的放右边，然后将temp放到合适的位置
{
	int i = 0;
	int j = L.length;
	int temp = 0;
	int pivot=L.elem[0];           //以L.elem[0]为基准
    while(i<j)
	{
		while(j>i&&L.elem[j]%2 == 0)
			j--;                   //从后向前扫描
		L.elem[i] = L.elem[j];
		while(i<j&&L.elem[i]%2 != 0)
			i++;                   //从前向后扫描
		L.elem[j] = L.elem[i];
	}
	L.elem[i] = pivot;
	    Quicksort(L,i,i-1);
        Quicksort(L,i+1,j);

}

void DisSort(Sqlist L)
{
	int i;
	for(i = 1;i<L.length;i++)
		printf("%d",L.elem);
}

int main()
{
	Sqlist L;
	int R[] = {10,31,11,25,65,17,24,32,19,28};
	CreateList(L,R);
	int i = 0;
	int j = 9;
	Quicksort(L,i,j);
	DisSort(L);
		printf("\n");
    return 0;
}
