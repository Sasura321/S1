#include<stdio.h>
typedef struct  
{
	int * elem;
	int length;
	int listsize;
}SqList;
void InitList_Sq(SqList *L)
{
	//��ʼ�����Ա�
	L->elem=(int * )malloc(10*sizeof(int));
	if(!L->elem) 
		exit(0);
	L->length=0;
	L->listsize=10;
}


 void DestroyList(SqList *L)
{
	//�������Ա�
	free(L->elem);
}

int main()
{
	SqList L;
	int i=0,k,pivot,j;
	InitList_Sq(&L);
	scanf("%d",&k);
	while(k>0)
		//�����Ա��︳ֵ
	{
		if(L.length>=L.listsize)
		{
			//��ǰ�洢�ռ�����  ���ӷ���
			int * newbase=(int *)realloc(L.elem,(L.listsize+10)*sizeof(int));
			if(!newbase) exit(0);
			L.elem=newbase;
			L.listsize+=10;
		}
		L.elem[i]=k;
		L.length++;
		i++;
		scanf("%d",&k);
	}
	i=0;
	j=L.length-1;
	pivot=L.elem [0];
	while(i<j)
	{
		while(j>i&&L.elem[j]%2==0)
			j--;
		L.elem[i]=L.elem[j];
		while(j>i&&L.elem[i]%2!=0)
			i++;
		L.elem[j]=L.elem[i];
	}
	L.elem[i]=pivot;
	for(i=0;i<L.length;i++)
		printf("%d ",L.elem [i]);
	DestroyList( &L);
	return 0;

}


	
