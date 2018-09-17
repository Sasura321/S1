//不允许创建临时变量，交换两个数的内容

#include <stdio.h>

int main()
{
	int a = 5;
	int b = 8;
	a = a^b;
	b = b^a;
	a = a^b;
	printf("%d  %d\n", a, b);
	return 0;
}