//��дһ���������ӱ�׼�����ȡCԴ���룬����֤���еĻ����Ŷ���ȷ�ĳɶԳ���

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
//			printf("����!");
//		while (ch[j] != EOF)
//		{
//			if (ch[j] == '{')
//				i++;
//			if (ch[j] == '}')
//				i--;
//		}
//	}/*
//		if (i == 0)
//			printf("��ȷ!");
//		else
//			printf("����!");*/
//
//	return 0;
//}
#include<stdio.h>
int main()
{
	int ch;
	int count = 0;
	while ((ch = getchar()) != EOF) //�ж�ch�Ƿ����-1
	{
		if (ch == '{')
		{
			count++;

		}
		if (ch == '}' && count == 0)
		{
			printf("��ƥ��\n");
			return 0;
		}
		if (ch == '}' && count != 0)
		{
			count--;

		}
	}

	if (count == 0)
	{
		printf("ƥ��\n");

	}
	else
	{
		printf("��ƥ��\n");
	}

	return 0;
}