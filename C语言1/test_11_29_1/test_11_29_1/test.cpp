//��һ��˳���L������Ԫ������ElemTypeΪ����
//���һ�������ܸ߼����㷨�������������Ƶ�ż����ǰ��

#include <stdio.h>
#include<stdlib.h>
#include<windows.h>
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10

typedef int  ElemType;
typedef  struct 
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

void InitList_Sq(SqList &L,int arr[])  //����һ�����Ա�
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	int i = 0;
	L.length=0;
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
	int j = L.length - 1;
	int temp = 0;
	while (i<j)
	{
		if ((L.elem[i] % 2) == 0)
		{
			temp = L.elem[i];
		}
		else
		{
			i++;
		}
		if ((L.elem[j] % 2) != 0)
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

void DisList(SqList L)  //���
{
	int i = L.length;
	while (i)
	{
		printf("%d", L.elem[i]);
		i--;
	}
}
int main()
	{
		SqList L;
		int arr[]={1,2,3,4,5,6,7,8};
		printf("��ʼ��\n");
		InitList_Sq(L,arr);
		printf("����\n");
		MoveList(L);
		DisList(L);
		system("pause");
		return 0;
	}
