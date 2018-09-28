//1.一个数组中只有两个数字是出现一次，其他所有数字都出现了两次,
//找出这两个数字，编程实现

#include<stdio.h>

int main()
{
	int arr[] = { 1, 6, 3, 4, 5, 2, 2, 3, 1, 6 };
	int i = 0;
	int j = 0;
	int count = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < len; i++)
	{
		count = 0;
		for (j = len - 1; j >= 0; j--)
		{
			if (arr[i] == arr[j])
				count++;
		}
		if (count == 1)
		{
			printf("%d出现一次\n", arr[i]);
		}
	}
	return 0;
}