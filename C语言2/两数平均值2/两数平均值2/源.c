//��ʹ��(a+b) /2���ַ�ʽ������������ƽ��ֵ

#include<stdio.h>

//int main()
//{
//	int a = 10;
//	int b = 30;
//	int avg = 0;
//	avg = (a + b) >> 1;  //�ұ�һλ�൱�ڳ���2
//	printf("%d\n", avg);
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 30;
//	int avg = 0;
//	avg = ((a^b) >> 1) + (a&b);
//	//&��a,b��������ͬΪ1����Ϊ1���൱�ڳ�2��
//	//^��01,10�����Ϊ1��������һλ���2��
//	printf("%d\n", avg);
//	return 0;
//}
 

//���
int add (int a,int b)
{
	int t = 0;
	do
	{
		t = a^b;
		b = (a&b) << 1;
		a = t;
	} while (b != 0);
	return a;
}
int main()
{
	printf("%d\n", add(5,3));
	return 0;
}