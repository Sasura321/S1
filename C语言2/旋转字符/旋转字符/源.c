//ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA,ABCD���������ַ��õ�CDAB

#include<stdio.h>

int string_length(char *str)
{
	int i = 0;
	for (i = 0; str[i] != '\0'; i++)
		;
	return i;
}

void recerve_string(char* str, int left, int right)
{
	int len = string_length(str);
	int i = left;
	int j = right;
	while (i < j)
	{
		int temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int main()
{
	char buf[] = "abcdefgh";
	int len = 0;
	len = string_length(buf);
	recerve_string(buf, 0, 2);
	recerve_string(buf, 3, len - 1);
	recerve_string(buf, 0, len - 1);
	printf("%s\n", buf);
	return 0;
}
