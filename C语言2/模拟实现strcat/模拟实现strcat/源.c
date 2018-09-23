//4.模拟实现strcat ,strcat是连接字符串的函数

#include<stdio.h>
#include<assert.h>

char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);

	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char dest[100] = "aaaaaaaaaaa";
	char src[] = "bbbbbbbbbbb";
	char* ch = my_strcat(dest, src);
	printf("%s\n", ch);
	return 0;
}