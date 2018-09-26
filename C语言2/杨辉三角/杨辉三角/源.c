//在屏幕上打印杨辉三角。

#include<stdio.h>

int main()
{
	int arr[100][100] = { 0 };
	int i = 0;
	int j = 0;
	int t = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j<10; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}
			if (i == j)
			{
				arr[i][j] = 1;
			}
			if (i>1 && j > 0)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (t = i; t < 10; t++)
		{
			printf(" ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("%-3d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
