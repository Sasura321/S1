//杨氏矩阵 有一个二维数组.数组的每行从左到右是递增的，
//每列从上到下是递增的.在这样的数组中查找一个数字是否存在。时间复杂度小于O(n);数组：
//1 2 3          1 3 4
//2 3 4          2 4 5
//3 4 5          4 5 6

//#include<stdio.h>
//
//void FindNum(int i,int j)
//{
//	int arr[][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
//	int num = 5;
//	int len1 = sizeof(arr) / sizeof(arr[0]);
//	int len2 = sizeof(arr[0]) / sizeof(int);
//	if (arr[i][j] == num || arr[len1-1][len2-1] == num)
//	{
//		printf("%d在数组中存在\n", num);
//	}
//	else
//	{
//		if (arr[i + 1][j] < arr[i][j + 1])
//		{
//			FindNum(i + 1, j);
//			i++;
//		}
//		else
//		{
//			FindNum(i, j + 1);
//			j++;
//		}
//	}
//	if (i > len1-1 && j > len1-1)
//	{
//		printf("%d在数组中不存在\n", num);
//	}
//}
//
//int main()
//{
//	int i = 0; 
//	int j = 0;
//	FindNum(i,j);
//	return 0;
//}



// 2. 杨氏矩阵
#include <stdio.h>
#define N 10

void show(int arr[N][N], int len)
{
	for (int i = 0; i< len; i++) {
		for (int j = 0; j<len; j++)
			printf("%3d ", arr[i][j]);
		printf("\n");
	}
}

void init(int arr[N][N], int len)
{
	for (int i = 0; i<len; i++) {
		for (int j = 0; j<len; j++) {
			arr[i][j] = (i + 1) * (j + 1) * 2;
		}
	}
}

int main()
{
	int arr[N][N] = {0};
	init(arr, N);
	show(arr, N);
	return 0;
}