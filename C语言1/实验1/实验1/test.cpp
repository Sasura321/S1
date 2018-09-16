//有一个顺序表L，假设元素类型ElemType为整数
//设计一个尽可能高级的算法，将所有奇数移到偶数的前面

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
	for (i = 0; i < 8; i++)
	{
		L.elem[i] = arr[i];  //引用数组arr[]
	    L.length++;          //得到顺序表L的长度
	}
	L.listsize = LIST_INIT_SIZE;  
	/*初始储存容量，listsize指顺序表当前分配的储存空间大小，
	进行其他操作造成空间不足时，可进行再分配，
	即为顺序表增加一个大小为储存LIST_INIT_SIZE个数据元素的空间*/
}

void MoveList(SqList &L)           //计算
{
    int i = 0;
    int j = L.length-1;
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
}

void DisList(SqList L)     //输出
{
	int i = 0;
	for(i = 0;i<L.length;i++)
		printf("%d  ", L.elem[i]);
	printf("\n");
}

int main()
{
	SqList L;
	int arr[] = {1,2,3,4,5,6,7,8};
	CreateList(L,arr);      //创建顺序表L，引用一个数组arr[]
	MoveList(L);            //将顺序表L中所有奇数移到偶数的前面
	printf("最终结果为：\n");
	DisList(L);             //将移动好的顺序表输出
	return 0;
}
