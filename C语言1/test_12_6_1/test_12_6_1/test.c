//��һ��˳���L������Ԫ������ElemTypeΪ����
//���һ�������ܸ߼����㷨�������������Ƶ�ż����ǰ��

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

void InitList_Sq(SqList &L)  //����һ�����Ա�
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	int i = 0;
	for(i = 0;i < 10;i++)
		L.elem[i] = rand()%100;
	L.length = 10;
	L.listsize = LIST_INIT_SIZE;//��ʼ��������
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

void DisList(SqlList L)  //���
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