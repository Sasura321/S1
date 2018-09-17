//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的,请找出这个数字(使用位运算)

#include<stdio.h>

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int tem = 0;
	for (i = 0; i <sz; i++)
	{
		tem = tem^arr[i];
	}
	printf("%d \n", tem);
	return 0;
}
