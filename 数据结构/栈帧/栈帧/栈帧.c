#include <stdio.h>

//lea ---> load effective address  加载有效地址

int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int main()
{
	int a = 10;
	int b = 20;
	int ret = 0;

	ret = Add(a, b);
	printf("ret = %d\n", ret);
	return 0;
}