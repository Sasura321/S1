#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = -6; i <= 6; i++)
	{
		for (j = 1; j <= abs(i); j++)
		{
			printf(" ");
		}
		for (j = abs(i) - 6; j <= 6 - abs(i); j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

