/*��������к������㷨�ܽᣬ������������������Ϊ�����������0*/
#include<stdio.h>
int max_part1(int a[],int n)//����ÿ�����У���ͼ��㷨�����Ӷȣ�O(N^3) 
{
	int sum=0,max=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			sum=0; 
			for(int k=i;k<=j;k++)
			{
				sum=sum+a[k];
			}
			if(sum>max) max=sum;
		}
	}
	return max;
}
int max_part2(int a[],int n)//�м��㷨���ڵ�ǰ���еĻ��������Ԫ�أ����Ӷȣ�O(N^2) 
{
	int sum=0,max=0;
	for(int i=0;i<n;i++)
	{
		sum=0;
		for(int j=i;j<n;j++)
		{
			sum=sum+a[j];
			if(sum>max) max=sum;
		}
	}
	return max;
}
int max_part3(int a[],int n)//�߼��㷨�����ߴ�����˳�������ƽ���
//����ǰ�ʹ��ڵ�ǰ������к������������кͣ�����ǰ��С��0���õ�ǰ�͡����Ӷȣ�O(N)����죬�������� 
{
	int sum=0,max=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+a[i];
		if(sum>max) max=sum;
		else if(sum<0) sum=0;	
	}
	return max;	
} 
int main()
{
	int n,i,a[100000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("%d\n",max_part1(a,n));
	printf("%d\n",max_part2(a,n));
	printf("%d\n",max_part3(a,n));
}
