//����һ�����飬ʵ�ֺ���init() ��ʼ�����顢ʵ��empty() ������顢
//ʵ��reverse() �����������Ԫ�ص����á�Ҫ�� : �Լ���ƺ����Ĳ���������ֵ

#include <stdio.h>
#include <stdlib.h>

void init(int *arr, int len)
{
	int i = 0;
	printf("��������Ԫ�أ�");
	for (i = 0; i < len; i++)
	{
		scanf("%d ", &arr[i]);
	}
	printf("��ʼ������Ϊ��");
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
	printf("������飺");
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
	printf("��������\n");
	for (i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}
}

void menu()
{
	printf("*************************************\n");
	printf("*********  1.��ʼ������     *********\n");
	printf("*********  2.�������       *********\n");
	printf("*********  3.����Ԫ�ص����� *********\n");
	printf("*********  4.�˳�����       *********\n");
	printf("*************************************\n");
}

int main()
{
	int *arr;
	int length = 0;
	int num = 0;
	int count = 1;
	printf("����Ĵ�С��");
    scanf("%d", &length);
	arr = (int *)malloc(length);
	menu();
	while (count)
	{
		printf("\n��ѡ��:");
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
			printf("����������������룺\n");
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
//	printf("��ʼ������\n");
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
//	printf("�������\n");
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
//	printf("��������\n");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d", arr[i]);
//	}
//}
//void menu()
//{
//	printf("*******************************************\n");
//	printf("**************1����ʼ������****************\n");
//	printf("**************2���������******************\n");
//	printf("**************3������Ԫ�ص�����************\n");
//	printf("**************4���˳�����******************\n");
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
//	printf("����Ĵ�С��");
//	scanf("%d", &n);
//	arr = (int *)malloc(n);//��̬�ڴ���䣬����n=5��ֻ�������ĸ�Ԫ�أ������Ϊ\0
//	menu();
//
//	while (count)
//	{
//		printf("\n��ѡ��:\n");
//		scanf("%d", &a);
//		printf("\n");
//		switch (a)
//		{
//		case 1:init(arr, n - 1);//n������Ԫ�ظ���������\0������Ԫ���±����û�Ҫ��һ��
//			count = 1;
//			break;
//		case 2:empty(arr, n - 1);
//			break;
//		case 3:reverse(arr, n - 1);
//			break;
//		case 4:count = 0;
//			break;
//		default:
//			printf("����������������룺\n");
//		}
//	}
//	system("pause");
//	return 0;
//}