//判断两个数组中是否有相同的元素，有则输出“Yes”，没有则输出“No”

#include <stdio.h>

int main()
{
	int arr1[] = {1,2,3,4};
	int arr2[] = {5,6,7,8,9};
	int i = 0,j=0;
	int sz1 = sizeof(arr1)/sizeof(arr1[0]);
	int sz2 = sizeof(arr2)/sizeof(arr2[0]);
	int count = 0;
	for(i = 0;i<sz1;i++)
	{
		for(j = 0;j<sz2;j++)
		{
			if(arr1[i] = arr2[j])
				count++;
		}
	}
	if(count == 0)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}
