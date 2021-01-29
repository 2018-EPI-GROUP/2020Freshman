/*求最大子列和问题算法总结，若序列中所有整数皆为负数，则输出0*/
#include<stdio.h>
int max_part1(int a[],int n)//遍历每个子列，最低级算法：复杂度：O(N^3) 
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
int max_part2(int a[],int n)//中级算法：在当前子列的基础上逐加元素，复杂度：O(N^2) 
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
int max_part3(int a[],int n)//高级算法：在线处理，按顺序依次推进，
//若当前和大于当前最大子列和则更新最大子列和，若当前和小于0重置当前和。复杂度：O(N)，最快，起初难理解 
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
