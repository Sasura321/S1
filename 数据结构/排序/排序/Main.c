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

	printf("²åÈëÅÅÐò:\n");
	InsetSort(array, size);
	PrintArray(array, size);
	InsetSort2(array, size);
	PrintArray(array, size);

	printf("Ï£¶ûÅÅÐò:\n");
	ShellSort(array, size);
	PrintArray(array, size);
	ShellSortNor(array, size);
	PrintArray(array, size);

	printf("¶ÑÅÅÐò:\n");
	HeapSort(array, size);
	PrintArray(array, size);

	printf("Ñ¡ÔñÅÅÐò:\n");
	SelectSortOP(array, size);
	PrintArray(array, size);

	printf("¿ìËÙÅÅÐò:\n");
	BubbleSort(array, size);
	PrintArray(array, size);

	printf("¿ìËÙÈýÖÖÅÅÐò:\n");
	Partion_1(array, 0, size - 1);
	PrintArray(array, size);
	Partion_2(array, 0, size - 1);
	PrintArray(array, size);
	Partion_3(array, 0, size - 1);
	PrintArray(array, size);

	printf("¿ìËÙÅÅÐò£¨µÝ¹é£©:\n");
	__QuickSort(array, 0, size - 1);
	PrintArray(array, size);

	printf("¹é²¢ÅÅÐò:\n");
	MergeSortLoop(array, size);
	PrintArray(array, size);
}

int main()
{
	Test();
	return 0;
}