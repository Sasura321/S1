//��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ�����������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����

#include<stdio.h>
#include<time.h>

int main()
{
	char arr[10] = "";
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("��������ȷ���룺");
		scanf("%s",&arr);
		if (strcmp(arr, "abcdef") == 0)
			break;
	}
	if (i < 3)
	{
		printf("��½�ɹ���\n");
	}
	else
	{
		printf("�˳�����\n");
	}
	return 0;
}
