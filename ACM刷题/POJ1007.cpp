#include<stdlib.h>
#include<stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct DNA //**??DNA???**/
{
	string str;//**????,?????????**//
	int count;
}w[1001];
bool comp(DNA x,DNA y)//**??????**//
{
	return x.count<y.count;
}
int main()
{
	int s,n,i,j,k;
	scanf("%d %d",&s,&n);
	for(i=0;i<n;i++)
	{
	    cin>>w[i].str;//**??C?????,?????C++**//
		w[i].count=0;
		for(j=0;j<=s-2;j++)//**????**//
		{
			for(k=j+1;k<=s-1;k++)
			{
				if(w[i].str[j]>w[i].str[k]) w[i].count++;
			}
		}
	}
	stable_sort(w,w+n,comp);
	for(i=0;i<n;i++)
	{
		cout<<w[i].str<<endl;
 
	}
	return 0;
}                         
