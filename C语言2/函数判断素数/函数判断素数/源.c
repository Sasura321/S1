//ʵ��һ������,�ж�һ�����ǲ���������

#include<stdio.h>

void prime(int m)
{
	int i = 0;
	for (i = 2; i < m; i++)
	{
		if (m%i == 0)
		{
			break;
		}
	}
	if (m == i)
	{
		printf("������\n");
	}
	else
	{
		printf("��������\n");
	}
}

int main()
{
	int n = 8;
	prime(n);
	return 0;
}