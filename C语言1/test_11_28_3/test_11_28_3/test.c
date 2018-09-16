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
	printf("输入线性表L的个数：");
	scanf("%d",&L.length);
	printf("输入线性表L的%d个元素",L.length);
	for(i = 0;i<L.len;i++)
		scanf("%d",&L.elem[i]);
	movel(L);
	printf("输出移动后的线性表：%d",L.elem)
	return 0;
}
 