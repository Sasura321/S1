//�ж������������Ƿ�����ͬ��Ԫ�أ����������Yes����û���������No��
#include <stdio.h>
int main()
{
	int arr1[] = {1,2,3,4};
	int arr2[] = {5,6,7,8,9};
	int i = 0,j=0;
	for(i = 0;i<4;i++)
	{
		for(j = 0;j<5;j++)
			if(arr1[i] = arr2[j])
			{
				printf("Yes\n");
				break;
			}
	if(j<5)break;
	}
	if(i == 3)
		printf("No\n");
	return 0;
}

//�����ԣ�����������������е���