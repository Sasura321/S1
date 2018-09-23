//将三个数按从大到小输出

//#include <stdio.h>
//
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = 8;
//	int swap = 0;
//	if (c > b)
//	{
//		swap = b;
//		b = c;
//		c = swap;
//	}
//	if (b > a)
//	{
//		swap = a;
//		a = b;
//		b = swap;
//	}
//	if (c > b)
//	{
//		swap = b;
//		b = c;
//		c = swap;
//	}
//	printf("%d  %d  %d\n", a, b, c);
//	return 0;
//}

#include <stdio.h>

void swap(int *px, int *py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

int main()
{
	int a = 3;
	int b = 5;
	int c = 8;
	if (c > b)
	{
		swap(&c,&b);
	}
	if (b > a)
	{
		swap(&b, &a);
	}
	if (c > b)
	{
		swap(&c, &b);
	}
	printf("%d  %d  %d\n", a, b, c);
	return 0;
}