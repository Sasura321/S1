//写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回-1.(折半查找)

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int key = 0;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = 0;
	printf("请输入你需要查找的数字： ");
	scanf("%d",&key);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key > arr[mid])
		{
			left = mid;
		}
		else if (key < arr[mid])
		{
			right = mid;
		}
		else
		{
			break;
		}
	}
	if (left <= right)
	{
		printf("%d\n", mid);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}