// 1. дһ������Խ�һ�����ֵ�����λ��ż��λ������

//#include<stdio.h>
//
//#define SWAPOE(num) ( (((num)&0X55555555)<<1) | (((num)&0XAAAAAAAA)>>1) ) 
//
//int main()
//{
//	printf("%d\n", SWAPOE(101));
//	return 0;
//}

// 2. ʹ�ú�ʵ������������ϴ�ֵ
#include<stdio.h>

#define MAX(a,b) ( ((a) > (b)) ? (a):(b) ) 

int main()
{
	printf("%d\n", MAX(2,3));
	return 0;
}