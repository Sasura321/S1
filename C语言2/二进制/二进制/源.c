//写一个函数返回参数二进制中1的个数

#include<stdio.h>
int main()
{
	int num = 1;
	int count = 0;
	while (num)
	{
		count++;
		num = num &(num - 1);
	}
	printf("二进制中1的个数 = %d\n", count);
	return 0;
}