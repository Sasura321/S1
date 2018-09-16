//求一元二次方程的解

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
		printf("不是一元二次方程");
	}
	else
	{
		double disc = b*b-4*a*c;
	    if(disc>-EXP && disc<EXP)
		{
			printf("方程有一个根:%lf"，-b/(2*a));
		}
		else if(disc >= EXP)
		{
		   printf("方程有两个根:%lf %lf",\
			   (-b+sqr(disc))/(2*a),(-b-sqr(disc))/(2*a));
		}
	   else
	   {
		   printf("方程无解");
		}
	}
	return 0;
}