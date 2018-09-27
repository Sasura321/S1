//2.使用可变参数，实现函数，求函数参数的平均值

#include<stdio.h>
#include<stdarg.h>

int average(int n, ...)
{
	va_list arg;//声明一个变量
	int i = 0;
	int sum = 0;
	va_start(arg, n);//初始化，把arg变量设置为指向可变参数部分的第一个参数
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);//va_arg返回参数的值
	}
	return sum / n;
	va_end(arg);//va_end置为空指针
}

int main()
{
	int m = 5;
	int n = 7;
	int avg = average(2, m, n);
	printf("avg = %d\n", avg);
	return 0;
}