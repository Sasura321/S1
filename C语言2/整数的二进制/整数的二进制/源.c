//����int (32λ) ����m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ? ��������:1999 2299,������� : 7

#include<stdio.h>

int main()
{
	int m = 1999;
	int n = 2299;
	int tmp = 0;
	int count = 0;
	tmp = m^n;
	while (tmp)
	{
		tmp = tmp&(tmp - 1);
		count++;
	}
	printf("%d\n", count);
	return 0;
} 