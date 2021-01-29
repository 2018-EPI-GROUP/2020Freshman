#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n)
	{
		int a[n],i,sum=0;
		for(i=0;i<n;i++)
		{
		cin>>a[i];
		sum=sum+a[i];
		}
		cout<<sum<<endl;
		cin>>n;
	}
	return 0;
}
