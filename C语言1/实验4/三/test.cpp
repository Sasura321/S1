#include <stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE  100  //���Ա�洢�ռ�ĳ��·�����
#define LISTINCREMENT   10   //���Ա�洢�ռ�ķ�������

typedef int  ElemType;
typedef  struct 
{
	ElemType *elem;   //�洢�ռ��ַ
	int length;       //��ǰ����
	int listsize;     //��ǰ����Ĵ洢����
}SqList;

void CreateList(SqList &L,int arr[]) 
//����һ��һά����arr[]����һ�����Ա�L
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	int i = 0;
	L.length = 0;
	for (i = 0; i < 10; i++)
	{
		L.elem[i] = arr[i];  //��������arr[]
	    L.length++;          //�õ�˳���L�ĳ���
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

void QuickSort(SqList &L,int s,int t)//���������㷨
{
	int i=s,j=t;
 	int temp=0; //��׼
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
	    printf("���ֵĽ��  :");
		DisSort(L);
	} 
} 

int main()
{
	SqList L;
 	int arr[]={50,84,36,44,22,90,75,19,25,68};
	CreateList(L,arr);
 	int s=0,t=9;
	printf("����ǰ������:");
 	DisSort(L);
    QuickSort(L,s,t);
	printf("���ս��    :");
 	DisSort(L);
 	return 0;
  } 

