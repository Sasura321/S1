//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 �� AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC

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