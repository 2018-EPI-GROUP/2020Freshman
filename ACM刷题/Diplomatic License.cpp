#include<stdio.h>
typedef struct p
{
	double x;//建议使用double 
	double y;
}po;
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d",n);
		po pos[n];//测试数据是大于3的技术，不用考虑n=0 
		for(i=0;i<n;i++)
		{
			pos[i].x=0;pos[i].y=0;
			scanf("%lf %lf",&pos[i].x,&pos[i].y);
			if(i) printf(" %.6f %.6f",1.0*(pos[i-1].x+pos[i].x)/2,1.0*(pos[i-1].y+pos[i].y)/2);
			if(i==n-1) printf(" %.6f %.6f",1.0*(pos[0].x+pos[i].x)/2,1.0*(pos[0].y+pos[i].y)/2);
			//最终要算首位坐标的中点 
		}
	printf("\n");
	}
	return 0;	
} 
