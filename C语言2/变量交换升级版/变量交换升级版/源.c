//����������ʱ����������������������

#include <stdio.h>

int main()
{
	int a = 5;
	int b = 8;
	a = a^b;
	b = b^a;
	a = a^b;
	printf("%d  %d\n", a, b);
	return 0;
}