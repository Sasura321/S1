//ģ��ʵ��printf���������������Ĺ��� 
// 
//��������溯���ĵ��á� 
//print("s ccc d.\n","hello",'b','i','t'��100); 
//����ԭ�ͣ� 
//print(char *format, ...) 
// 

//#include<stdio.h>
//
//int print(const char* str, ...)
//{
//	assert(str != NULL);
//	va_list arg;
//	va_start(arg, str);
//	int count = 0;
//	const char* dest = str;
//	while (*dest != '\0')
//	{
//		if (*dest == '%')
//		{
//			dest++;
//			switch (*dest)
//			{
//			case 'd':
//			}
//		}
//	}
//}
//
//int main()
//{
//	char str[] = "hello";
//	char arr = 'b';
//	int num = 100;
//	print(str, arr, num);
//	return 0;
//}

#include<stdio.h>
#include<stdarg.h>
#include<assert.h>

int print(const char* str, ...)
{
	assert(str != NULL);

	va_list arg;//����char* ���� arg
	int count = 0;
	int d = 0;
	char* dest = NULL;
	va_start(arg, str);//Ϊarg���г�ʼ��

	while (*str != '\0')
	{
		switch (*str)
		{
			case 'c':
			putchar(va_arg(arg, int));//ȡ��һ���������ַ�������ӡ
			count++;
			break;

			case 's':
			dest = (char*)va_arg(arg, int);//ȡ��һ�������ĵ�ַ
			while (*dest != '\0')//���ý����ý������
			{
				putchar(*dest);
				count++;
				dest++;
			}
			break;

			case 'd':
				d = va_arg(arg, int);
				char buf[10];
				_itoa(d, buf, 10);
				fputs(buf, stdout);
				while (d)
				{
					count++;
					d /= 10;
				}
				break;

		default:
			putchar(*str);  //����ֱ�ӽ�����ӡ
			count++;
			break;
		}
		str++;
	}

	va_end(arg);//��argָ���
	return count;
}

int main()
{
	print("s cccc d\n", "Hello", 'B', 'i', 't','!',666);
	return 0;
}


