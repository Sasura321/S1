//求10 个整数中最大值

#include <stdio.h>

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10 };
	int i = 0;
	int max = 0;
	for (i = 0; i <= 9; i++)
	{
		if (arr[i+1] > arr[i])
		{
			max = arr[i+1];
		}
		else
		{
			max = arr[i];
		}
	}
	printf("%d\n", max);
	return 0;
}