#include<stdio.h>
int xsort(int a[],int n)//Ñ¡Ôñ 
{
	int t,s=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				t=a[i];a[i]=a[j];a[j]=t;
				s++;
			}
		}
	}
	return s;
}
int msort(int a[],int n)//Ã°ÅÝ 
{
	int t,s=0,i,j;
	for(i=0;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(a[j-1]>a[j])
			{
				t=a[j-1];a[j-1]=a[j];a[j]=t;
				s++;
			}
		}
	}
	return s;
}
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int L;
		scanf("%d",&L);
		int a[L],i;
		for(i=0;i<L;i++) scanf("%d",&a[i]);
		printf("Optimal train swapping takes %d swaps.\n",msort(a,L));
	}
	return 0;
}
