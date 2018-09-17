//输出乘法口诀表

#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d   ", i, j, i*j);
			if (i == j)
				printf("\n");
		}
	}
	return 0;
}