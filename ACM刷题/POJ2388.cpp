#include<stdio.h>//ac
void sort(int a[],int n)
{
	int t;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				t=a[i];a[i]=a[j];a[j]=t;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,n);
	printf("%d",a[n/2]);
	return 0;
}
