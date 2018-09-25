//打印100~200 之间的素数

#include <stdio.h>
int main()
{
	int m = 0;
	int i = 0;
	for (m = 100; m <= 200; m++)
	{
		for (i = 2; i <= m ; i++)
		{
			if (m % i == 0)
			{
				
				break;
			}
			if (m==i)
				printf("%d  ", m);
		}
	}
	return 0;
}