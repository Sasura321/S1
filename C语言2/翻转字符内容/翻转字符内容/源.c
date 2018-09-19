//有一个字符数组的内容为:"student a am i",请你将数组的内容改为"i am a student".
//要求:不能使用库函数。只能开辟有限个空间(空间个数和字符串的长度无关)

#include<stdio.h>

int main()
{
	char arr[] = " student a am i";
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;
	int ret = sz;
	for (i = sz - 1; i >= 0; i--)
	{
		if (arr[i] == ' ')
		{
			for (j = i; j < ret; j++)
			{
				printf("%c", arr[j]);
			}
			ret = i;
		}
	}
	printf("\n");
	return 0;
}

