//1.��������ʹ����ȫ����λ��ż��ǰ�档����һ���������飬ʵ��һ������,
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

#include<stdio.h>

void swap(int *arr,int sz)
{
	int i = 0;
	int j = sz-1;
	int m = 0;
	while (i != j)
	{
		if (arr[i] % 2 == 0)
		{
			if (arr[j] % 2 != 0)
			{
				m = arr[i];
				arr[i] = arr[j];
				arr[j] = m;
			}
			else
				j--;
		}
		else
			i++;
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap(arr,sz);
	return 0;
}