//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9, ���9 * 9�ھ������12, ���12 * 12�ĳ˷��ھ���

#include<stdio.h>

void Mul(int x, int y)
{
	int k = 0;
	scanf("%d", &k);
	for (x = 1; x <= k; x++)
	{
		for (y = 1; y <= x; y++)
		{
			printf("%d*%d=%-2d  ", x, y, x*y);
		}
		printf("\n");
	}
}

int main()
{
	int i = 0;
	int j = 0;
	Mul(i, j);
	return 0;
}