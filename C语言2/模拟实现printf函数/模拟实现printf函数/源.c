//模拟实现printf函数，可完成下面的功能 
// 
//能完成下面函数的调用。 
//print("s ccc d.\n","hello",'b','i','t'，100); 
//函数原型： 
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

	va_list arg;//定义char* 变量 arg
	int count = 0;
	int d = 0;
	char* dest = NULL;
	va_start(arg, str);//为arg进行初始化

	while (*str != '\0')
	{
		switch (*str)
		{
			case 'c':
			putchar(va_arg(arg, int));//取下一个参数的字符，并打印
			count++;
			break;

			case 's':
			dest = (char*)va_arg(arg, int);//取下一个参数的地址
			while (*dest != '\0')//利用解引用进行输出
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
			putchar(*str);  //其他直接将它打印
			count++;
			break;
		}
		str++;
	}

	va_end(arg);//将arg指向空
	return count;
}

int main()
{
	print("s cccc d\n", "Hello", 'B', 'i', 't','!',666);
	return 0;
}


