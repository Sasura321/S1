//3.使用可变参数，实现函数，求函数参数的最大值。

#include<stdio.h>
#include<stdarg.h>

int is_max(int n, ...)
{
	va_list arg;//声明一个变量
	int i = 0;
	int max = 0;
	va_start(arg, n); //初始化，把arg变量设置为指向可变参数部分的第一个参数
	for (i = 0; i < n; i++)
	{
		if (va_arg(arg, int)>max)//va_arg返回参数的值
		{
			max = va_arg(arg, int);
		}
	}
	return max;
	va_end(arg);//va_end置为空指针
}

int main()
{
	int m = 5;
	int n = 7;
	int max = is_max(2, m, n);
	printf("max = %d\n", max);
	return 0;
}