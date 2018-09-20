//实现一个函数判断year是不是润年。

#include<stdio.h>

void Year(int k)
{
	if ((k % 4 == 0 && k % 100 != 0) || (k % 400 == 0))
	{
		printf("是闰年！\n");
	}
	else
		printf("不是闰年！\n");
}

int main()
{
	int year = 0;
	printf("请输入一个需要判断的年份:");
	scanf("%d", &year);
	Year(&year);
	return 0;
}