//�ж�1000��--2000��֮�������

#include<stdio.h>
int main()
{
	int m = 0;
	for (m = 1000; m <= 2000; m ++)
	{
		if (m % 100 != 0 && m % 4 == 0) 
		{
			printf(" %d ",m);
		}
		if (m % 400 == 0)
		{
			printf("%d  ", m);
		}
	}
	return 0;
}