/*甜甜从小就喜欢画图画，最近他买了一支智能画笔，由于刚刚接触，
所以甜甜只会用它来画直线，于是他就在平面直角坐标系中画出如下的图形：
甜甜的好朋友蜜蜜发现上面的图还是有点规则的，于是他问甜甜：在你画的图中，我给你两个点，
请你算一算连接两点的折线长度（即沿折线走的路线长度）吧。第一个数是正整数N（≤100）。代表数据的组数。
每组数据由四个非负整数组成x1，y1，x2，y2；所有的数都不会大于100。对于每组数据，
输出两点(x1,y1),(x2,y2)之间的折线距离。
注意输出结果精确到小数点后3位。
Sample Input
5
0 0 0 1
0 0 1 0
2 3 3 1
99 99 9 9
5 5 5 5
Sample Output
1.000
2.414
10.646
54985.047
0.000*/
#include<stdio.h>
#include<math.h>
double length(int x1,int y1,int x2,int y2)
{
	if(x1==x2) return fabs(y1-y2);
	else if(y1==y2) return fabs(x1-x2);
	else return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int x1,y1,x2,y2,i,j,t;
		scanf("%d %d %d %d",x1,x2,y1,y2);
		if(x1>x2) 
		{
			t=x1;x1=x2;x2=t;t=y1;y1=y2;y2=t;
		}
		if(y2)
	}
}
