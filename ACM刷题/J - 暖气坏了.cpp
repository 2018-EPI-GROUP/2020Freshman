/*蒜头君家的暖气经常出问题，每当暖气坏了，蒜头君就会持续感冒m天（从坏的那天算起，两次感冒时间重叠不会累加）。
蒜头君去寻求预言家的帮助，预言家告诉他接下来 n次暖气片坏掉的时间。根据这个时间，蒜头君就能知道他未来获得感冒的总天数。
*/
#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n],i,j,cnt=0,flag=0,b[100000005];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		int t=a[i];
		for(j=0;j<m;j++)
		{
			b[t+j]++;
		} 
	}
	for(i=1;i<100000005;i++)
	if(b[i]!=0) cnt++;
	printf("%d",cnt);
}
