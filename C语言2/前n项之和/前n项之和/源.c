//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣����磺2+22+222+2222+22222

#include<stdio.h>

int main()
{
	int n = 0;
	int i = 0;
	int Sn = 0;
	scanf("%d", &n);
	for (i = 1; i <= 5; i++)
	{
		Sn = Sn + (10 * i*n + n);
	}
	printf("%d\n", Sn);
	return 0;
}