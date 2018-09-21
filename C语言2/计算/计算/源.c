//¼ÆËã1/1-1/2+1/3-1/4./.1.....+ 1/99- 1/100 µÄÖµ

//#include <stdio.h>
//
//int main()
//{
//	double i = 0.0;
//	double sum1 = 0.0;
//	double sum2 = 0.0;
//	for (i = 1;i <= 99; i+=2)
//	{
//		sum1 = sum1 + 1.0 / i;
//	}
//	for (i = 2; i <= 100; i+=2)
//	{
//		sum2 = sum2 + 1.0 / i;
//	}
//	sum1 = sum1 - sum2;
//	printf("sum1 = %lf\n", sum1);
//	return 0;
//}

#include<stdio.h>
 
int main()
{
	double sum = 0.0;
	int i = 0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum = sum + flag*1.0 / i;
		flag = -flag;
	}
	printf("%lf\n", sum);
	return 0;
}