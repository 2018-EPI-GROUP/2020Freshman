/*蒜头君就要放暑假了，他通过计算机预测出他暑假中每天的兴奋值 
。现在找出在暑假中哪段时间内蒜头君的心情值的最大，求出这个最大的心情值。
输入格式
第一行一个整数 n(1-10^5),表示暑假的天数。
第二行N个整数，每个整数ai（1-10^6）代表第i天的兴奋值。
 输出格式
一个整数，表示心情值的最大值。
样例解释
第三天到第五天的心情值最大，为 4*（6+4+5）=60*/
#include<stdio.h>
int getmin(int a[],int x,int y)
{
	int min=a[x];
	for(int m=x;m<y;m++)
	{
		if(a[m]<min) min=a[m];
	}
	return min; 
}
int getsum(int a[],int x,int y)
{
	int sum=0;
	for(int o=x;o<y;o++)
	{
		sum=sum+a[o];
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[100005],i,j,r,maxr=0;;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
	{
		r=getmin(a,i,j)*getsum(a,i,j);
		if(r>maxr) maxr=r;
	}
	}
	printf("%d",maxr);
} 
