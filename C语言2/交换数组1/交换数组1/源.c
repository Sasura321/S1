// 将数组A中的内容和数组B中的内容进行交换(数组一样大)

#include<stdio.h>

int main()
{
	int arr1[] = { 0, 1, 2, 3, 4 };
	int arr2[] = { 5, 6, 7, 8, 9 };
	int i = 0;
	int swap = 0;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	for (i = 0; i < sz; i++)
	{
		swap = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = swap;
		printf("%d  ", arr1[i]);
	}
	printf("\n");
	for (i = 0; i <  sz; i++)
	{
		printf("%d  ", arr2[i]);
	}
	printf("\n");
	return 0;
}