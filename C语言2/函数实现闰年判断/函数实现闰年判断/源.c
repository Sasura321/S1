//ʵ��һ�������ж�year�ǲ������ꡣ

#include<stdio.h>

void Year(int k)
{
	if ((k % 4 == 0 && k % 100 != 0) || (k % 400 == 0))
	{
		printf("�����꣡\n");
	}
	else
		printf("�������꣡\n");
}

int main()
{
	int year = 0;
	printf("������һ����Ҫ�жϵ����:");
	scanf("%d", &year);
	Year(&year);
	return 0;
}