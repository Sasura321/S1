//���һ��������ÿһλ

#include<stdio.h>

int main()
{
	int num = 0;
	printf("������һλ��λ����");
	scanf("%d", &num);
	printf("%d  %d  %d\n", num/100,num%100/10,num%10);
	return 0;
}