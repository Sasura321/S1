//Ä£ÄâÊµÏÖstrcpy

#include<stdio.h>
#include<assert.h>

char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);

	char* ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char src[] = "aaaaaaaaaaa";
	char dest[] = "bbbbbbbbbbb";
	char* ch = my_strcpy(dest, src);
	printf("%s\n", ch);
	return 0;
}
