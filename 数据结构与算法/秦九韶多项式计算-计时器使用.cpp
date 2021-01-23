#include<math.h>
#include<stdio.h>
#include<time.h>
/*给定另一个100阶多项式 f(x)=1+x+x^2/2+x^3/3+....+x^100/100,用不同方法计算x=1.1并且比较一下运行时间？*/
double func1(double x)//普通算法 
{
	int i;
	double sum=1;
	for(i=1;i<101;i++)
	{
		sum+=1.0*pow(x,i)/i;
	}
	return sum;
}
double func2(double x)//优化：秦九韶算法 
{
	int i;
	double p=1.0/100;
	for(i=100;i>1;i--)
	{
		p=x*p+1.0/(i-1);
	}
	p=x*p+1;
	return p; 
}
int main()
{
	clock_t start,stop;
	double dur1,dur2;//持续时间变量名 
	start=clock();
	for(int i=0;i<10000;i++) 
	func1(1.1);
	printf("%f\n",func1(1.1));
	stop=clock();
	dur1=(double)(stop-start)/10000;
	start=clock();
	for(int i=0;i<10000;i++) 
	func2(1.1);
	printf("%f\n",func2(1.1));
	stop=clock();
	dur2=(double)(stop-start)/10000;
	printf("普通算法运行时间为：%f ticks，秦九韶算法运行时间为：%f ticks",dur1,dur2);
	return 0;
}
