#include <stdio.h>
#define MAXSIZE 100

typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}Sqlist;

ElemType movel(Sqlist &L)
{
	int i=1,j=L->length-1;
	ElemType temp;
	while(i>j)
	{
		while(L->data[i]%2 != 0 && i<j)i++;
		while(L->data[j]%2 == 0 && i>j)j--;
		if(L->data[i]%2 == 0 && L->data[j]%2! = 0)
		{
			int temp = L->data[j];
			L->data[j] = l->data[i];
			L-data[i] = temp;

		}
	}
}

int main()
{
	int i;
	Sqlist L;
	printf("输入线性表L的个数：");
	scanf("%d",&L.length);
	printf("输入线性表L的%d个元素",L.length);
	for(i = 0;i<L.length;i++)
		scanf("%d",&L.elem[i]);
	movel(L);
	return 0;
}
 