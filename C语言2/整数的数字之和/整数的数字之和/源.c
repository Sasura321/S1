//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19 

#include<stdio.h>

int DigitSum(int n)
{
	if (n > 0)
	{
		return (n%10 + DigitSum(n/10));
	}
	else
		return 0;
}

int main()
{
	srand((unsigned int)time(NULL));
	int n = rand() % 1000;
	/*int n = 1729;*/
	printf("%d\n", DigitSum(n));
	return 0;
}