//1.递归和非递归分别实现求第n个斐波那契数。

#include<stdio.h>

//非递归
int fib1(int n)
{
	int n1 = 1;
	int n2 = 1;
	int num = 2;
	int i = 0;
	for (i = 0; i < n-3; i++)
	{
		n1 = n2;
		n2 = num;
		num = n1 + n2;
	}
	return num;
}

//递归
int fib2(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib2(n - 2) + fib2(n - 1);
}

int main()
{
	int n = 5;
	printf("fib1 = %d\n", fib1(n));
	printf("fib2 = %d\n", fib2(n));
	return 0;
}

