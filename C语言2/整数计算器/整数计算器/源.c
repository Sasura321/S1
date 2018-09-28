//1.使用main函数的参数，实现一个整数计算器，程序可以接受三个参数，
//第一个参数“-a”选项执行加法，“-s”选项执行减法，“-m”选项执行乘法，
//“-d”选项执行除法，后面两个参数为操作数。

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[], char *env[])
{
	int num = 0;
	if (argc != 4)
	{
		printf("error!\n");
	}
	switch (argv[1][1])
	{
	case 'a':
		num = atoi(argv[1])+atoi(argv[2]);
		break;
	case 's':
		num = atoi(argv[1]) - atoi(argv[2]);
		break;
	case 'm':
		num = atoi(argv[1]) * atoi(argv[2]);
		break;
	case 'd':
		num = atoi(argv[1]) / atoi(argv[2]);
		break;
	default:
		printf("error!\n");
		break;
	}
	printf("%d", num);
	return 0;
}
