#include <stdio.h>
#define MAXSIZE 100

typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}Sqlist;

int movel(Sqlist L)
{
	int i=0,j=L->length-1;
	ElemType temp;
	ElemType pivot = L->data[0];
	while(i>j)
	{
		while(L->data[i]%2!=0 && i<j)i++;
		while(L->data[j]%2==0 && i>j)j--;
		if(L->data[i]%2 == 0 && L->data[j]%2! = 0)
		{
			int temp = L->data[j];
			L->data[j] = L->data[i];
			L-data[i] = temp;
		}
	}

}

int main()
{
	int i;
	Sqlist L;
	printf("�������Ա�L�ĸ�����");
	scanf("%d",&L.length);
	printf("�������Ա�L��%d��Ԫ��",L.length);
	for(i = 0;i<L.len;i++)
		scanf("%d",&L.elem[i]);
	movel(L);
	printf("����ƶ�������Ա�%d",L.elem)
	return 0;
}
 