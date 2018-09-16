#include <stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE  100  //线性表存储空间的出事分配量
#define LISTINCREMENT   10   //线性表存储空间的分配增量

typedef int  ElemType;
typedef  struct 
{
	ElemType *elem;   //存储空间基址
	int length;       //当前长度
	int listsize;     //当前分配的存储容量
}SqList;

void CreateList(SqList &L,int arr[]) 
//引用一个一维数组arr[]构造一个线性表L
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	int i = 0;
	L.length = 0;
	for (i = 0; i < 10; i++)
	{
		L.elem[i] = arr[i];  //引用数组arr[]
	    L.length++;          //得到顺序表L的长度
	}
	L.listsize = LIST_INIT_SIZE; 
}

void DisSort(SqList L)
{
	int k=1;
 	for(k=0;k<L.length;k++)
		printf("%d  ",L.elem[k]);
	printf("\n");
 }

void QuickSort(SqList &L,int s,int t)//快速排序算法
{
	int i=s,j=t;
 	int temp=0; //基准
	if(s<t)
	{
		temp=L.elem[s];
	 	while(i != j)
		{ 
			while(j>i&&L.elem[j]>= temp)
				j--;
			L.elem[i]=L.elem[j];
		    while(i<j&&L.elem[i]<=temp)
				i++;
		    L.elem[j]=L.elem[i];
		}
		L.elem[i]=temp;
		QuickSort(L,s,i-1);
		QuickSort(L,i+1,t);
	    printf("划分的结果  :");
		DisSort(L);
	} 
} 

int main()
{
	SqList L;
 	int arr[]={50,84,36,44,22,90,75,19,25,68};
	CreateList(L,arr);
 	int s=0,t=9;
	printf("排序前的数组:");
 	DisSort(L);
    QuickSort(L,s,t);
	printf("最终结果    :");
 	DisSort(L);
 	return 0;
  } 

