//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵ�,���ҳ��������(ʹ��λ����)

#include<stdio.h>

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int tem = 0;
	for (i = 0; i <sz; i++)
	{
		tem = tem^arr[i];
	}
	printf("%d \n", tem);
	return 0;
}
