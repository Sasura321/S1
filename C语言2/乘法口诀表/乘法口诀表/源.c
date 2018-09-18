//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9, 输出9 * 9口诀表，输出12, 输出12 * 12的乘法口诀表

#include<stdio.h>

void Mul(int x, int y)
{
	int k = 0;
	scanf("%d", &k);
	for (x = 1; x <= k; x++)
	{
		for (y = 1; y <= x; y++)
		{
			printf("%d*%d=%-2d  ", x, y, x*y);
		}
		printf("\n");
	}
}

int main()
{
	int i = 0;
	int j = 0;
	Mul(i, j);
	return 0;
}