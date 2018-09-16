//��һ��˳���L������Ԫ������ElemTypeΪ����
//���һ�������ܸ߼����㷨�������������Ƶ�ż����ǰ��

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

void InitList(SqList &L,int arr[])  //����һ�����Ա�
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	int i = 0;
	L.length = 0;
	for (i = 0; i < 8; i++)
	{
		L.elem[i] = arr[i];
	    L.length++;
	}
	L.listsize = LIST_INIT_SIZE;//��ʼ��������
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



void DisList(SqList L)  //���
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
