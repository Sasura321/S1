//4. 编写一个函数reverse_string(char * string)（递归实现） 
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。

#include<stdio.h>
#include<string.h>
#include<assert.h>

int my_strlen(char *string)//求字符串长度  
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
		temp = string[0];//交换第一个和最后一个字符，将最后一个字符制成’\0’  
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