//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:
//A˵ : �����ҡ�
//B˵ : ��C��
//C˵ : ��D��
//D˵ : C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

//
//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	for (a = 0; a <= 1;a++)
//	for (b = 0; b <= 1; b++)
//	for (c = 0; c <= 1; c++)
//	for (d = 0; d <= 1; d++)
//	{
//		if ((a == 1 && c == 1 && d == 1 && d == 0) ||(a == 0 && c == 0 && d == 1 && d == 0) 
//			||(a == 0 && c == 1 && d == 0 && d == 0) || (a == 0 && c == 1 && d == 1 && d == 1))
//		{
//			if (a == 1)
//				printf("A������\n");
//			if (b == 1)
//				printf("B������\n");
//			if (c == 1)
//				printf("C������\n");
//			if (d == 1)
//				printf("D������\n");
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if (killer = 'a')
//		{
//			a = 0;
//			b = 0;
//			c = 0;
//			d = 1;
//		}
//		if (killer = 'b')
//		{
//			a = 1;
//			b = 0;
//			c = 0;
//			d = 1;
//		}
//		if (killer = 'c')
//		{
//			a = 1;
//			b = 1;
//			c = 0;
//			d = 1;
//		}
//		if (killer = 'd')
//		{
//			a = 1;
//			b = 0;
//			c = 1;
//			d = 0;
//		}
//	}
//	if (a == 1)
//		printf("A������\n");
//	if (b == 1)
//		printf("B������\n");
//	if (c == 1)
//		printf("C������\n");
//	if (d == 1)
//	    printf("D������\n");
//	return 0;
//}

#include<stdio.h>

int main()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("killer = %c\n", killer);
		}
	}
	return 0;
}
