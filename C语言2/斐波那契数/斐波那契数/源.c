//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������

#include<stdio.h>

//�ǵݹ�
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

//�ݹ�
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

