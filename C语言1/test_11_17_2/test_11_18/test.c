//����1-5���weekday,����6-7���weekend

#include<stdio.h>

int main()
{
	int day = 0;;
	scanf("%d",&day);
	switch(day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("workday");
		break;
	case 6:
	case 7:
		printf("weekend");
		break;
	default:
		printf("���벻�Ϸ�");
		break;
	}
		return 0;
}