//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

#include<stdio.h>
#include<string.h>

int mystrcmp(char *s1, char *s2, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i]-s2[i]);
		}
	}
	return 0;
}

int turn_string(int *str1, int *str2)
{
	char buf[100] = {0};
	int ret = 0;
	int i = 0;
	int j = 0;
	for (i = 0; str1[i] != '\0'; i++)
	{
		buf[i] = str1[i];
	}
	for (j = 0; str1[j] != '\0'; j++)
	{
		buf[i++] = str1[j];
	}
	for (i = 0; i < strlen(str1); i++)
	{
		if (mystrcmp(str1 + i, str2, strlen(str2)) == 0)
			ret = 1;
	}
	return ret;
}

int main()
{
	printf("%d\n", turn_string("AABCD", "ABCDA"));
	return 0;
}