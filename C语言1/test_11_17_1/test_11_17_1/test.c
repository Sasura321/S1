//��һԪ���η��̵Ľ�

#include <stdio.h>
#include <math.h>

#define EXP = 0.000000001

int main()
{
	double a = 0.0;
	double b = 0.0;
    double c = 0.0;
	printf("Please input a,b,c:");
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a>-EXP && a<EXP)
	{
		printf("����һԪ���η���");
	}
	else
	{
		double disc = b*b-4*a*c;
	    if(disc>-EXP && disc<EXP)
		{
			printf("������һ����:%lf"��-b/(2*a));
		}
		else if(disc >= EXP)
		{
		   printf("������������:%lf %lf",\
			   (-b+sqr(disc))/(2*a),(-b-sqr(disc))/(2*a));
		}
	   else
	   {
		   printf("�����޽�");
		}
	}
	return 0;
}