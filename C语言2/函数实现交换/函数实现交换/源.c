//使用函数实现两个数的交换

#include<stdio.h>

void swap(int *px, int *py)
{
	int swp = 0;
	swp = *px;
	*px = *py;
	*py = swp;
}

int main()
{
	int a = 1;
	int b = 5;
	swap(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}