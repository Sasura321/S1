//实现一个函数,判断一个数是不是素数。

#include<stdio.h>

void prime(int m)
{
	int i = 0;
	for (i = 2; i < m; i++)
	{
		if (m%i == 0)
		{
			break;
		}
	}
	if (m == i)
	{
		printf("是素数\n");
	}
	else
	{
		printf("不是素数\n");
	}
}

int main()
{
	int n = 8;
	prime(n);
	return 0;
}