#include <iostream>

using namespace std;

/*
����10������Ԫ�ص�������ð�����򷨰���С������������
*/

//��������
void Swap(int *x, int *y)
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

//ð������
void BubbleSort(int *array,int len)
{
	int i, j;

	//ֻ�����len-1�ˣ�0~len-2������
	for (i = 0; i < len-1; i++)
	{
		//ÿһ������������еĽ�������
		for (j = 0; j < len - 1 - i; j++)
		{
			if (array[j]>array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
			}
		}
	}
}

//��ӡ����
void Print(int *array,int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
}

int main()
{
	int array[] = { 5, 6, 1, 3, 7, 8, 9, 4, 22, 41, 11 };
	int len = sizeof(array) / sizeof(array[0]);
	BubbleSort(array, len);
	Print(array, len);
	return 0;
}