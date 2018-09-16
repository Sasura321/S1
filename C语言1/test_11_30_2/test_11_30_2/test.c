#include<stdio.h>

void divide(int arr[],int size)//利用数据结构中快排的思想
{
	int i = 0;
	int temp = 0;
	int *p = arr;
	int *q = arr+size-1;
	while(*p!=*q)
	{
		if((*p%2)==0)
		{
			temp = *p;
		}
		else
		{
			p++;
		}
		if((*q%2)==1)
		{
			*p = *q;
			*q = temp;
		}
		else
		{
			q--;
		}
	}
	for(i=0; i<size; i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[] = {8,4,6,1,5,5,7,6,4,6,9,8,3,5,55,89,54,36};
	int size = sizeof(arr)/sizeof(arr[0]);
	divide(arr,size);
	return 0 ;
}
