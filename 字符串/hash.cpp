#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10005
#define seed 20020207
#define ULL unsigned long long

using namespace std;

int n;
long long h[MAXN];
string s[MAXN];

ULL hash(string s) {
	ULL value=0;
	int x=1;
	for(int i=0;i<s.length();i++) {
		value+=s[i]*x*seed;
		x*=10;
	}
	return value;
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		cin>>s[i];
		h[i]=hash(s[i]);
	}
	int ans=0;
	sort(h+1,h+n+1);
	for(int i=1;i<=n;i++) {
		if(h[i]!=h[i+1]) ans++;
	}
	printf("%d",ans);
	return 0;
}
