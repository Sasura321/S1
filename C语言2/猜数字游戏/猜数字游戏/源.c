//��������Ϸ

#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("*******��ӭ����������Ϸ*******\n\n");
	int n = 0;
	int m = 0;
	n = rand() % 100;
	printf("��ʼ������(0~100): ");
	scanf("%d", &m);
	while (m != n)
	{
		if (m > n)
		{
			printf("�´��ˣ�����������\n");
			scanf("%d", &m); 
		}
		else if (m < n)
		{
			printf("��С�ˣ�����������\n");
			scanf("%d", &m); 
		}
	}
	if (m == n)
	{
		printf("��ϲ�㣬�¶��ˣ�\n");
		return 0;
	}
	printf("\n");
	printf("*********ллʹ��*************\n");
	return 0;
}