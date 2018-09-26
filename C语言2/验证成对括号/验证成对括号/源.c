//编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确的成对出现

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	char ch[] = { 0 };
//	gets(ch);
//	for (j = 0; j < (sizeof(ch) / sizeof(ch[0])); j++)
//	{
//		if (ch[j] == '}')
//			printf("错误!");
//		while (ch[j] != EOF)
//		{
//			if (ch[j] == '{')
//				i++;
//			if (ch[j] == '}')
//				i--;
//		}
//	}/*
//		if (i == 0)
//			printf("正确!");
//		else
//			printf("错误!");*/
//
//	return 0;
//}
#include<stdio.h>
int main()
{
	int ch;
	int count = 0;
	while ((ch = getchar()) != EOF) //判断ch是否等于-1
	{
		if (ch == '{')
		{
			count++;

		}
		if (ch == '}' && count == 0)
		{
			printf("不匹配\n");
			return 0;
		}
		if (ch == '}' && count != 0)
		{
			count--;

		}
	}

	if (count == 0)
	{
		printf("匹配\n");

	}
	else
	{
		printf("不匹配\n");
	}

	return 0;
}