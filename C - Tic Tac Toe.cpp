#include<iostream>
using namespace std;
int n,i,j,X,O;
char a[3][4];
int iswin(char c)
{
	for(i=0;i<3;i++)//判断一行或一列连三个获胜 
	{
		for(j=0;j<3&&a[i][j]==c;j++);
			if(j==3) return 1;
		for(j=0;j<3&&a[j][i]==c;j++);
		if(j==3) return 1;
	}
	for(i=0;i<3&&a[i][i]==c;i++);//判断主对角线 
	if(i==3) return 1;
	for(i=0;i<3&&a[i][2-i]==c;i++);//判断副对角线 
	if(i==3) return 1;
	return 0;
}
int main()
{
	for(scanf("%d",&n);n;n--)
	{
		X=0,O=0,i=0,j=0; //一定要记得初始化 
		scanf("%s%s%s",a[0],a[1],a[2]);
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)//统计O X个数 
			{
				if(a[i][j]=='X') X++;
				if(a[i][j]=='O') O++;
			}
		}
		if(O>X||X-O>1||iswin('X')&&iswin('O')||X-O!=1&&iswin('X')||X!=O&&iswin('O'))
		{
		printf("no\n");continue;
		}
		printf("yes\n");
	}
}
