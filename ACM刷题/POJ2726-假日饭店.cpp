#include<iostream>
#include<algorithm>
using namespace std;
typedef struct hot
{
	int d;
	int c;
}hotel;
int main()
{
	int N,i,j,sum=0,flag=0;
	scanf("%d", &N);
	hotel hot1;
	while (scanf("%d", &hot1.d) != EOF)
	{
		if(hot1.d==0) break;
		scanf("%d",&hot1.c);
		hotel hot2;
		if (flag)
		{
			if (hot2.d<hot1.d && hot2.c>hot1.c || hot2.d > hot1.d && hot2.c < hot1.c) sum++;
		}
		scanf("%d", &hot2.d);
		flag = 1;
		if(hot2.d==0) break;
		scanf("%d",&hot2.c);
		if (hot2.d<hot1.d && hot2.c>hot1.c || hot2.d > hot1.d && hot2.c < hot1.c) sum++;
	}
	cout <<sum;
	return 0;
}
