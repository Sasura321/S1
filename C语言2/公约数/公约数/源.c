//求两个数的最大公约数 

#include <stdio.h>

//int main()
//{
//	int a = 9;
//	int b = 12;
//	int i = 0;
//	int gad = 0;
//	for (i=1; i<=a && i<=b; i++)
//	{
//		if (a%i == 0 && b%i == 0)
//		{
//			gad = i;
//		}
//	}
//	printf("%d\n", gad);
//	return 0;
//}


//辗转相除法
#include <stdio.h>

int main()
{
	int a = 24;
	int b = 18;
	int tmp = 0;
	while((tmp = a%b) != 0)
	{
		a = b;
		b = tmp;
	}	
	printf("%d\n", b);
	return 0;
}