//4. ��дһ������reverse_string(char * string)���ݹ�ʵ�֣� 
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������

#include<stdio.h>
#include<string.h>
#include<assert.h>

int my_strlen(char *string)//���ַ�������  
{
	int count = 0;
	while (*string++)
	{
		count++;
	}
	return count;
}

void reverse_string(char* string,int len)
{
	char temp;
	assert(string);
	if (*string)
	{
		temp = string[0];//������һ�������һ���ַ��������һ���ַ��Ƴɡ�\0��  
		string[0] = string[len-1];
		//string[len-1] = '/0';
		reverse_string(string + 1,len-2);
		string[len-1] = temp;
	}
}

int main()
{
	char string[20] = "abcdefgh";
	int len = my_strlen(string);
	reverse_string(string,len);
	printf("%s\n", string);
	return 0;
}