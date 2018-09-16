//求一个N介数组的所有元素之和

#include <stdio.h>

int main()
{
	int i = 0;
	int sum = 0;
	int arr[] = {1,2,3,4,5,6};
	int sz = sizeof(arr)/sizeof(arr[0]);
	for(i = 0;i<sz;i++)
	{
		sum = sum+arr[i];
	}
	printf("%d",sum);
	return 0;
	
}