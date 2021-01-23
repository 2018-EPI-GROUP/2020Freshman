#include<math.h>
#include<stdio.h>
#include<time.h>
/*������һ��100�׶���ʽ f(x)=1+x+x^2/2+x^3/3+....+x^100/100,�ò�ͬ��������x=1.1���ұȽ�һ������ʱ�䣿*/
double func1(double x)//��ͨ�㷨 
{
	int i;
	double sum=1;
	for(i=1;i<101;i++)
	{
		sum+=1.0*pow(x,i)/i;
	}
	return sum;
}
double func2(double x)//�Ż����ؾ����㷨 
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
	double dur1,dur2;//����ʱ������� 
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
	printf("��ͨ�㷨����ʱ��Ϊ��%f ticks���ؾ����㷨����ʱ��Ϊ��%f ticks",dur1,dur2);
	return 0;
}
