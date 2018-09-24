//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水。编程实现。

#include<stdio.h>

int main()
{
	int count = 20;      //喝了的汽水数量
	int soda = 20;       // 汽水数量
	int temp = soda / 2; //换得的汽水数量
	int ret = soda % 2;  //剩下的汽水数量
	while (soda > 1)
	{
		count += temp;
		soda = temp + ret;
		temp = soda / 2;
		ret = soda % 2;
	}
	printf("20元可以喝 %d 瓶汽水\n", count);
	return 0;
}