//两个int (32位) 整数m和n的二进制表达中，有多少个位(bit)不同? 输入例子:1999 2299,输出例子 : 7

#include<stdio.h>

int main()
{
	int m = 1999;
	int n = 2299;
	int tmp = 0;
	int count = 0;
	tmp = m^n;
	while (tmp)
	{
		tmp = tmp&(tmp - 1);
		count++;
	}
	printf("%d\n", count);
	return 0;
} 