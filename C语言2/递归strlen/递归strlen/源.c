//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen

#include<stdio.h>
#include<string.h>
#include<assert.h>

//�ǵݹ�
int my_strlen1(char *str)  
{
	int count = 0;
	assert(str);
	while (*str++)
	{
		count++;
	}
	return count;
}

//�ݹ�
int my_strlen2(char *str)
{
	assert(str);
	if (*str == '/0')
		return 0;
	else
		return 1 + strlen(str + 1);
}

int main()
{
	int len1 = my_strlen1("abcdefgh");
	int len2 = my_strlen2("abcdefgh");
	printf("�ǵݹ�: len1 = %d\n",len1);
	printf("�ݹ�  : len2 = %d\n",len1);
	return 0;
}