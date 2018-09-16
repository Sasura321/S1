//��һ��˳���L������Ԫ������ElemTypeΪ����
//���һ�������ܸ߼����㷨�������������Ƶ�ż����ǰ��

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
	for (i = 0; i < 8; i++)
	{
		L.elem[i] = arr[i];  //��������arr[]
	    L.length++;          //�õ�˳���L�ĳ���
	}
	L.listsize = LIST_INIT_SIZE;  
	/*��ʼ����������listsizeָ˳���ǰ����Ĵ���ռ��С��
	��������������ɿռ䲻��ʱ���ɽ����ٷ��䣬
	��Ϊ˳�������һ����СΪ����LIST_INIT_SIZE������Ԫ�صĿռ�*/
}

void MoveList(SqList &L)           //����
{
    int i = 0;
    int j = L.length-1;
    int temp = 0;
    int pivot=L.elem[0];           //��L.elem[0]Ϊ��׼
    while(i<j)
	{
		while(j>i&&L.elem[j]%2 == 0)
			j--;                   //�Ӻ���ǰɨ��
		L.elem[i] = L.elem[j];
		while(i<j&&L.elem[i]%2 != 0)
			i++;                   //��ǰ���ɨ��
		L.elem[j] = L.elem[i];
	}
	L.elem[i] = pivot;
}

void DisList(SqList L)     //���
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
	CreateList(L,arr);      //����˳���L������һ������arr[]
	MoveList(L);            //��˳���L�����������Ƶ�ż����ǰ��
	printf("���ս��Ϊ��\n");
	DisList(L);             //���ƶ��õ�˳������
	return 0;
}
