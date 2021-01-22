#include<stdio.h>
int main()
{
	int T,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		int i,j,n,flag=1;
		scanf("%d",&n);
		int a[n][n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) scanf("%d",&a[i][j]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]<0||a[i][j]!=a[n-i-1][n-j-1])
				{
					flag=0;break;
				}
			}
			if(!flag) break;
		}
		printf("Test #%d: ",t);
		if(flag) printf("Symmetric\n");
		else printf("Non-Symmetric\n");
	}
}
