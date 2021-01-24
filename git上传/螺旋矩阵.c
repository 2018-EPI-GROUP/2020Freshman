#include <stdio.h>
#define N 20
int main()
{
	int i,j,k,base,n;
	base =1;
	printf("请输入你想要得到几阶矩阵:\n");
	scanf("%d",&n);	
	int a[N][N]={0};
	for(k=0;k<n/2;k++)     //n/2为矩阵的矩形数目
	{
		for(i=k;i<=n-1-k;i++)//第一区块
			a[k][i]=base++;;
		for(j=k+1;j<n-1-k;j++)//第二区块
			a[j][n-1-k]=base++;
		for(i=n-1-k;i>k;i--)//第三区块
			a[n-1-k][i]=base++;
		for(j=n-1-k;j>k;j--)//第四区块
			a[j][k]=base++;
		if(n%2==1)
			a[(n-1)/2][(n-1)/2]=base;//为基数是奇数的矩阵的中心点进行赋值
	}
	//输出矩阵
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%-4d",a[i][j]);
		printf("\n");
	}
	return 0;
}  
