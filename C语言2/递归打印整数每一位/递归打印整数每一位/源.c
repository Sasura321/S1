//5.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 

#include<stdio.h>

void print(int num)
{
	if (num > 9)
		print(num / 10);
	printf(" %d ", num % 10);
}

int main()
{
	int num = 12345;
	print(num);
	printf("\n");
	return 0;
}