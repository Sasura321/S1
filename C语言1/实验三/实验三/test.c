#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define LIST_INIT_SIZE  100  //���Ա�洢�ռ�ĳ�ʼ������
 
typedef struct
{
	int *elem;   //�洢�ռ��ַ
	int R[MAXSIZE+1];
	int length;
}Sqlist;

void CreateList(SqList &L,int R[]) 
//����һ��һά����arr[]����һ�����Ա�L
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	int i = 0;
	L.length = 0;
	for (i = 0; i < 10; i++)
	{
		L.elem[i] = R[i];  //��������arr[]
	    L.length++;          //�õ�˳���L�ĳ���
	}
	
}

void Quicksort(Sqlist &L,int i,int j)
//��������tempС��Ԫ�طŵ���ߣ���ķ��ұߣ�Ȼ��temp�ŵ����ʵ�λ��
{
	int i = 0;
	int j = L.length;
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
