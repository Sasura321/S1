//浮点型和零进行比较（1）

#include <stdio.h>

int main()
{
	double i = 20.0;
	double j = i/7.0;
	if(j*7.0 == i)
		printf("equal\n");
	else
		printf("not equal\n");
	return 0;
}