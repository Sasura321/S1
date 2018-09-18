//编写一个程序，可以直接接收键盘字符，
//如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出

#include<stdio.h>

int main()
{
	char c1 ;
	char c2 ;
	scanf("%c", &c1);
	if (c1 >= 'a' && c1 <= 'z')
	{
		c2 = c1 - 32;
	}
	else if (c1 >= 'A' && c1 <= 'Z')
	{
		c2 = c1 + 32;
	}
	printf("%c\n", c2);
	return 0;
}