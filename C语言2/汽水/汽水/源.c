//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֡�

#include<stdio.h>

int main()
{
	int count = 20;      //���˵���ˮ����
	int soda = 20;       // ��ˮ����
	int temp = soda / 2; //���õ���ˮ����
	int ret = soda % 2;  //ʣ�µ���ˮ����
	while (soda > 1)
	{
		count += temp;
		soda = temp + ret;
		temp = soda / 2;
		ret = soda % 2;
	}
	printf("20Ԫ���Ժ� %d ƿ��ˮ\n", count);
	return 0;
}