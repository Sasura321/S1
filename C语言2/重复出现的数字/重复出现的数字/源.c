//1.һ��������ֻ�����������ǳ���һ�Σ������������ֶ�����������,
//�ҳ����������֣����ʵ��

#include<stdio.h>

int main()
{
	int arr[] = { 1, 6, 3, 4, 5, 2, 2, 3, 1, 6 };
	int i = 0;
	int j = 0;
	int count = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < len; i++)
	{
		count = 0;
		for (j = len - 1; j >= 0; j--)
		{
			if (arr[i] == arr[j])
				count++;
		}
		if (count == 1)
		{
			printf("%d����һ��\n", arr[i]);
		}
	}
	return 0;
}