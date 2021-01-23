#include<iostream>
#include<algorithm>
#define max 1000000
using namespace std;
bool cmp1(int x,int y)
{
	return x>y;
}
int main()
{
	int i, n, m;
	scanf("%d %d", &n, &m);
	int a[max];
	for (i = 0;i < n;i++) scanf("%d", &a[i]);
	sort(a, a + n,cmp1);
	printf("%d",a[0]);
	for (i = 1;i<m;i++) printf(" %d", a[i]);
	return 0;
}
