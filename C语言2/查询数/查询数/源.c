//编写程序数一下1到100 的所有整数中出现多少次数字9

#include<stdio.h>

int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
		{
			count++;
		}
		if (i / 10 == 9)
		{
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}