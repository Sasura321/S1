//编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”，密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。

#include<stdio.h>
#include<time.h>

int main()
{
	char arr[10] = "";
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入正确密码：");
		scanf("%s",&arr);
		if (strcmp(arr, "abcdef") == 0)
			break;
	}
	if (i < 3)
	{
		printf("登陆成功！\n");
	}
	else
	{
		printf("退出程序！\n");
	}
	return 0;
}
