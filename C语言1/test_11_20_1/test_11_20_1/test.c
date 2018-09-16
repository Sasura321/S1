//浮点型和零进行比较（2）

#define EXP = 0.000000001
#include <stdio.h>

int main()
{
	double i = 20.0;
	double j = i/7.0;
	if((j*7.0-i)>-EXP&&(j*7.0-i)<EXP)
	{
		printf("not equal\n");
	}
	else
	{
		printf("equal\n");
	}
	return 0;
}