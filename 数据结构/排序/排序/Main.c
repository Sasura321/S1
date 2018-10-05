#include "SortPow.h"

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Test()
{
	int array[] = { 10, 3, 5, 1, 4, 2, 9, 7, 6, 8, 0 };
	int size = sizeof(array) / sizeof(int);

	printf("��������:\n");
	InsetSort(array, size);
	PrintArray(array, size);
	InsetSort2(array, size);
	PrintArray(array, size);

	printf("ϣ������:\n");
	ShellSort(array, size);
	PrintArray(array, size);
	ShellSortNor(array, size);
	PrintArray(array, size);

	printf("������:\n");
	HeapSort(array, size);
	PrintArray(array, size);

	printf("ѡ������:\n");
	SelectSortOP(array, size);
	PrintArray(array, size);

	printf("��������:\n");
	BubbleSort(array, size);
	PrintArray(array, size);

	printf("������������:\n");
	Partion_1(array, 0, size - 1);
	PrintArray(array, size);
	Partion_2(array, 0, size - 1);
	PrintArray(array, size);
	Partion_3(array, 0, size - 1);
	PrintArray(array, size);

	printf("�������򣨵ݹ飩:\n");
	__QuickSort(array, 0, size - 1);
	PrintArray(array, size);

	printf("�鲢����:\n");
	MergeSortLoop(array, size);
	PrintArray(array, size);
}

int main()
{
	Test();
	return 0;
}