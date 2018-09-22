//2.编写一个函数实现n^k，使用递归实现 

#include<stdio.h>

int power(int n, int k)
{
	if (k > 0)
		return n* power(n, k - 1);
	else
		return 1;
}

int main()
{
	srand((unsigned int)time(NULL));
	int n = rand() % 10 + 1;
	int k = rand() % 10 + 1;
	printf("%d\n", power(n, k));
	return 0;
}