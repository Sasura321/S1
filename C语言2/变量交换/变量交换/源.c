//给定两个整形变量的值，将两个值的内容进行交换。

#include <stdio.h>

int main()
{
	int a = 5;
	int b = 8;
	int c = 0;
	c = a;
	a = b;
	b = c;
	printf("%d  %d\n", a, b);
	return 0;
}