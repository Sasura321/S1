//5.递归方式实现打印一个整数的每一位 

#include<stdio.h>

void print(int num)
{
	if (num > 9)
		print(num / 10);
	printf(" %d ", num % 10);
}

int main()
{
	int num = 12345;
	print(num);
	printf("\n");
	return 0;
}