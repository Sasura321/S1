//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19 

#include<stdio.h>

int DigitSum(int n)
{
	if (n > 0)
	{
		return (n%10 + DigitSum(n/10));
	}
	else
		return 0;
}

int main()
{
	srand((unsigned int)time(NULL));
	int n = rand() % 1000;
	/*int n = 1729;*/
	printf("%d\n", DigitSum(n));
	return 0;
}