//д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ�������-1.(�۰����)

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int key = 0;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = 0;
	printf("����������Ҫ���ҵ����֣� ");
	scanf("%d",&key);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key > arr[mid])
		{
			left = mid;
		}
		else if (key < arr[mid])
		{
			right = mid;
		}
		else
		{
			break;
		}
	}
	if (left <= right)
	{
		printf("%d\n", mid);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}