//输出一个整数的每一位

#include<stdio.h>

int main()
{
	int num = 0;
	printf("请输入一位三位数：");
	scanf("%d", &num);
	printf("%d  %d  %d\n", num/100,num%100/10,num%10);
	return 0;
}