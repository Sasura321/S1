//2.ʹ�ÿɱ������ʵ�ֺ���������������ƽ��ֵ

#include<stdio.h>
#include<stdarg.h>

int average(int n, ...)
{
	va_list arg;//����һ������
	int i = 0;
	int sum = 0;
	va_start(arg, n);//��ʼ������arg��������Ϊָ��ɱ�������ֵĵ�һ������
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);//va_arg���ز�����ֵ
	}
	return sum / n;
	va_end(arg);//va_end��Ϊ��ָ��
}

int main()
{
	int m = 5;
	int n = 7;
	int avg = average(2, m, n);
	printf("avg = %d\n", avg);
	return 0;
}