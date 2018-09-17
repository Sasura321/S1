//猜数字游戏

#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("*******欢迎来到猜字游戏*******\n\n");
	int n = 0;
	int m = 0;
	n = rand() % 100;
	printf("开始猜数字(0~100): ");
	scanf("%d", &m);
	while (m != n)
	{
		if (m > n)
		{
			printf("猜大了！请重新输入\n");
			scanf("%d", &m); 
		}
		else if (m < n)
		{
			printf("猜小了！请重新输入\n");
			scanf("%d", &m); 
		}
	}
	if (m == n)
	{
		printf("恭喜你，猜对了！\n");
		return 0;
	}
	printf("\n");
	printf("*********谢谢使用*************\n");
	return 0;
}