//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说 : 不是我。
//B说 : 是C。
//C说 : 是D。
//D说 : C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

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
//				printf("A是凶手\n");
//			if (b == 1)
//				printf("B是凶手\n");
//			if (c == 1)
//				printf("C是凶手\n");
//			if (d == 1)
//				printf("D是凶手\n");
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
//		printf("A是凶手\n");
//	if (b == 1)
//		printf("B是凶手\n");
//	if (c == 1)
//		printf("C是凶手\n");
//	if (d == 1)
//	    printf("D是凶手\n");
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
