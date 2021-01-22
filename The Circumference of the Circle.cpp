#include<stdio.h>
#include<math.h>
#define pi 3.141592653589793 
typedef struct p
{
	double x;
	double y;
}point;
int main() 
{
	point p1,p2,p3;
	while(scanf("%lf %lf %lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y)!=EOF)
	{
		double s1=sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
		double s2=sqrt(pow(p2.x-p3.x,2)+pow(p2.y-p3.y,2));
		double s3=sqrt(pow(p1.x-p3.x,2)+pow(p1.y-p3.y,2));
		double p=(s1+s2+s3)/2.0;
		double s=sqrt(p*(p-s1)*(p-s2)*(p-s3));
		double d=(s1*s2*s3)/(2*s);
		long double l=d*pi;//测试数据很大，使用long double 
		printf("%.2llf\n",l);
	}
	return 0;
}
