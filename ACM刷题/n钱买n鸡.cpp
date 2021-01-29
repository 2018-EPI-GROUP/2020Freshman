#include<stdio.h>
int main()
{
	int n,i,j,flag=0,x,g,m;
	scanf("%d",&n);
	for(x=0;x<=n;x=x+3)
	{
		for(g=0;g<=n/5;g++)
		{
			for(m=0;m<n/3;m++)
			{
				if(x+g+m==n&&x/3+m*3+g*5==n)
				printf("%d %d %d\n",g,m,x);
				flag=1;
			}
		}
	}
	if(!flag) printf("No Answer.");
	return 0;
}
