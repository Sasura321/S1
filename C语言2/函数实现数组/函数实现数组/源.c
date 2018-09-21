//创建一个数组，实现函数init() 初始化数组、实现empty() 清空数组、
//实现reverse() 函数完成数组元素的逆置。要求 : 自己设计函数的参数，返回值

#include <stdio.h>
#include <stdlib.h>

void init(int *arr, int len)
{
	int i = 0;
	printf("输入数组元素：");
	for (i = 0; i < len; i++)
	{
		scanf("%d ", &arr[i]);
	}
	printf("初始化数组为：");
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}

void empty(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
	printf("清空数组：");
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}

void reverse(int *arr, int len)
{
	int temp = 0, i = 0;
	for (i = 0; i < len / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = temp;
	}
	printf("逆置数组\n");
	for (i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}
}

void menu()
{
	printf("*************************************\n");
	printf("*********  1.初始化数组     *********\n");
	printf("*********  2.清空数组       *********\n");
	printf("*********  3.数组元素的逆置 *********\n");
	printf("*********  4.退出程序       *********\n");
	printf("*************************************\n");
}

int main()
{
	int *arr;
	int length = 0;
	int num = 0;
	int count = 1;
	printf("数组的大小：");
    scanf("%d", &length);
	arr = (int *)malloc(length);
	menu();
	while (count)
	{
		printf("\n请选择:");
		scanf("%d", &num);
		printf("\n");
		switch (num)
		{
		case 1:init(arr, length-1);
			break;
		case 2:empty(arr, length-1);
			break;
		case 3:reverse(arr, length-1);
			break;
		case 4:count = 0;
			break;
		default:
			printf("输入错误，请重新输入：\n");
		}
	}
	return 0;
}

//void init(int *arr, int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", &arr[i]);//arr[len] = '\0';
//	}
//	printf("初始化数组\n");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d", arr[i]);
//	}
//}
//void empty(int *arr, int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		arr[i] = 0;
//	}
//	printf("清空数组\n");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d", arr[i]);
//	}
//}
//void reverse(int *arr, int len)
//{
//	int temp = 0, i = 0;
//	for (i = 0; i < len / 2; i++)
//	{
//		temp = arr[i];
//		arr[i] = arr[len - 1 - i];
//		arr[len - 1 - i] = temp;
//	}
//	printf("逆置数组\n");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d", arr[i]);
//	}
//}
//void menu()
//{
//	printf("*******************************************\n");
//	printf("**************1、初始化数组****************\n");
//	printf("**************2、清空数组******************\n");
//	printf("**************3、数组元素的逆置************\n");
//	printf("**************4、退出程序******************\n");
//	printf("*******************************************\n");
//}
//int main()
//{
//	int *arr;
//	int n = 0;
//	int m = 0;
//	int a = 0;
//	int count = 1;
//	/*int len = 0;*/
//	printf("数组的大小：");
//	scanf("%d", &n);
//	arr = (int *)malloc(n);//动态内存分配，输入n=5，只能输入四个元素，第五个为\0
//	menu();
//
//	while (count)
//	{
//		printf("\n请选择:\n");
//		scanf("%d", &a);
//		printf("\n");
//		switch (a)
//		{
//		case 1:init(arr, n - 1);//n是数组元素个数，包括\0，数组元素下标引用还要减一；
//			count = 1;
//			break;
//		case 2:empty(arr, n - 1);
//			break;
//		case 3:reverse(arr, n - 1);
//			break;
//		case 4:count = 0;
//			break;
//		default:
//			printf("输入错误，请重新输入：\n");
//		}
//	}
//	system("pause");
//	return 0;
//}