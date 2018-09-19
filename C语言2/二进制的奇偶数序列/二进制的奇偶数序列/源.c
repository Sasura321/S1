//获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列

#include<stdio.h>

int main()
{
	int num = -1;
	int i = 0;
	int k = 0;
	for (i = 32; i >= 2; i-=2)
	{
		k = (num >> i) & 1;
		printf("%d ", k);
	}
	printf("\n");
	for (i = 31; i >= 1; i -= 2)
	{
		k = (num >> i) & 1;
		printf("%d ", k);
	}
	printf("\n");
	return 0;
}


//int main()
//{
//	10
//	00000000000000000000000000001010
//	int num = 2863311530;
//	int i = 0;
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	return 0;
//}
