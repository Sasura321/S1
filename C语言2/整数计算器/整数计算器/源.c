//1.ʹ��main�����Ĳ�����ʵ��һ��������������������Խ�������������
//��һ��������-a��ѡ��ִ�мӷ�����-s��ѡ��ִ�м�������-m��ѡ��ִ�г˷���
//��-d��ѡ��ִ�г�����������������Ϊ��������

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[], char *env[])
{
	int num = 0;
	if (argc != 4)
	{
		printf("error!\n");
	}
	switch (argv[1][1])
	{
	case 'a':
		num = atoi(argv[1])+atoi(argv[2]);
		break;
	case 's':
		num = atoi(argv[1]) - atoi(argv[2]);
		break;
	case 'm':
		num = atoi(argv[1]) * atoi(argv[2]);
		break;
	case 'd':
		num = atoi(argv[1]) / atoi(argv[2]);
		break;
	default:
		printf("error!\n");
		break;
	}
	printf("%d", num);
	return 0;
}
