#include<iostream>
using namespace std;
long long ji[14];
long long jie(int n)
{
	if(n==0||n==1) return 1;
	else return n*jie(n-1);
}
void cal()//离线计算，存入数组，防止重复调用，导致超时 
{
	ji[8]=40320;ji[9]=362880;ji[10]=3628800;ji[11]=39916800;ji[12]=479001600;ji[13]=6227020800;
}
int main()
{
	int n;
	cal();
	while(scanf("%d",&n)!=EOF)
	{
		if(n>=8&&n<=13) printf("%lld\n",ji[n]);
		if(n>13) printf("Overflow!\n");
		else if(n>=0&&n<8) printf("Underflow!\n");
		else if(n<0)
		{
			if(n%2==0) printf("Underflow!\n");
				else if(n%2!=0) printf("Overflow!\n");
		}	
	}
}
