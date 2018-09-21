// 1. 写一个宏可以将一个数字的奇数位和偶数位交换。

//#include<stdio.h>
//
//#define SWAPOE(num) ( (((num)&0X55555555)<<1) | (((num)&0XAAAAAAAA)>>1) ) 
//
//int main()
//{
//	printf("%d\n", SWAPOE(101));
//	return 0;
//}

// 2. 使用宏实现两个数中求较大值
#include<stdio.h>

#define MAX(a,b) ( ((a) > (b)) ? (a):(b) ) 

int main()
{
	printf("%d\n", MAX(2,3));
	return 0;
}