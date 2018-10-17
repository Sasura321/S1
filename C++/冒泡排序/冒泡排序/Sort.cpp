#include <iostream>

using namespace std;

/*
把有10个整数元素的数组用冒泡排序法按由小到大升序排列
*/

//交换函数
void Swap(int *x, int *y)
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

//冒泡排序
void BubbleSort(int *array,int len)
{
	int i, j;

	//只需进行len-1趟（0~len-2）排序
	for (i = 0; i < len-1; i++)
	{
		//每一趟排序所需进行的交换次数
		for (j = 0; j < len - 1 - i; j++)
		{
			if (array[j]>array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
			}
		}
	}
}

//打印函数
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