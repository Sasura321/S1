//��һ���ַ����������Ϊ:"student a am i",���㽫��������ݸ�Ϊ"i am a student".
//Ҫ��:����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ�(�ռ�������ַ����ĳ����޹�)

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

