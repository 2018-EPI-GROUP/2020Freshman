/*��ͷ����Ҫ������ˣ���ͨ�������Ԥ����������ÿ����˷�ֵ 
�������ҳ���������Ķ�ʱ������ͷ��������ֵ�������������������ֵ��
�����ʽ
��һ��һ������ n(1-10^5),��ʾ��ٵ�������
�ڶ���N��������ÿ������ai��1-10^6�������i����˷�ֵ��
 �����ʽ
һ����������ʾ����ֵ�����ֵ��
��������
�����쵽�����������ֵ���Ϊ 4*��6+4+5��=60*/
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
