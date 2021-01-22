#include<iostream>
using namespace std;
long long sum=0;
int i,j;
long long f(int n)
{
	if(n%10>0) return n%10;
	else if(n==0) return 0;
	else return f(n/10);
}
void solve(int p,int q)
{
	if(q-p<9) 
	{
	for(i=p;i<=q;i++) sum=sum+f(i);return;
	}
	else
	{
		while(p%10)
		{
			sum=sum+f(p);
			p++;
		}
		while(q%10)
		{
			sum=sum+f(q);
			q--;
		}
		sum=sum+45*(q-p)/10;
		solve(p/10,q/10);//?
	}
}
int main()
{
	long long p,q;
	while(scanf("%lld %lld",&p,&q)!=EOF)
	{
		sum=0;
		if(p<0&&q<0) return 0;
		solve(p,q);
		printf("%lld\n",sum);
	}
	return 0;
} 
