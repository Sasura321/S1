//不使用(a+b) /2这种方式，求两个数的平均值

#include<stdio.h>

//int main()
//{
//	int a = 10;
//	int b = 30;
//	int avg = 0;
//	avg = (a + b) >> 1;  //右边一位相当于除以2
//	printf("%d\n", avg);
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 30;
//	int avg = 0;
//	avg = ((a^b) >> 1) + (a&b);
//	//&把a,b二进制中同为1的与为1（相当于除2）
//	//^把01,10的异或为1（再右移一位则除2）
//	printf("%d\n", avg);
//	return 0;
//}
 

//求和
int add (int a,int b)
{
	int t = 0;
	do
	{
		t = a^b;
		b = (a&b) << 1;
		a = t;
	} while (b != 0);
	return a;
}
int main()
{
	printf("%d\n", add(5,3));
	return 0;
}