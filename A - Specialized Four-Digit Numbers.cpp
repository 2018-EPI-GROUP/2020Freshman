#include<iostream>
using namespace std;
int calc(int base,int n)//n转成base进制 
{
	int sum=0;
	while(n!=0)
	{
		sum=sum+n%base;
		n=n/base;
	}
	return sum;
}
int main()
{
	for(int i=2992;i<=9999;i++)
	{
		int a=calc(10,i);
		if(a==calc(12,i)&&calc(12,i)==calc(16,i))
		cout<<i<<endl;
	}
	return 0;
}
