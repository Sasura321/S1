//输入1-5输出weekday,输入6-7输出weekend

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
		printf("输入不合法");
		break;
	}
		return 0;
}