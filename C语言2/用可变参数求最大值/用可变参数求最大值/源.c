//3.ʹ�ÿɱ������ʵ�ֺ������������������ֵ��

#include<stdio.h>
#include<stdarg.h>

int is_max(int n, ...)
{
	va_list arg;//����һ������
	int i = 0;
	int max = 0;
	va_start(arg, n); //��ʼ������arg��������Ϊָ��ɱ�������ֵĵ�һ������
	for (i = 0; i < n; i++)
	{
		if (va_arg(arg, int)>max)//va_arg���ز�����ֵ
		{
			max = va_arg(arg, int);
		}
	}
	return max;
	va_end(arg);//va_end��Ϊ��ָ��
}

int main()
{
	int m = 5;
	int n = 7;
	int max = is_max(2, m, n);
	printf("max = %d\n", max);
	return 0;
}