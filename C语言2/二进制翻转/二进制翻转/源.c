//编写函数:unsigned int reverse_ bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//如 :在32位机器上25这个值包含下列各位 :00000000000000000000000011001
//翻转后 :(2550136832)  1001010000000000000000000000000
//程序结果返回 : 2550136832

#include<stdio.h>

unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	int count = 0;
	int num = value;
	int ret = 0;
	for (i = 1; i <= 32; i++)
	{
		if (num != 0)
		{
			num = num >> 1;
			count++;
		}
	}
	for (i = count-1; i >= 0; i--)
	{
		ret = ret + ((value>>i) << (count-1-i));
		value = value-((value>>i) << i);
	}
	value = ret << (32 - count);
	return value;
}

int main()
{
	printf("%u\n", reverse_bit(25));
	return 0;
}