//求有多少模式串在文本串里出现过 
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Trie {
	int ch[26];
	int end;
	int fail;
}AC[1000000];
int cnt=0;
int index(char c) {
	return c-'a';
} 
void Build_Trie(string s) {
	int l=s.length();
	int now=0;
	for(int i=0;i<l;i++) {
		int id=index(s[i]);
		if(AC[now].ch[id]==0) {
			AC[now].ch[id]=++cnt;
		}
		now=AC[now].ch[id];
	}
	AC[now].end++;
}
void Get_fail() {
	queue<int> q;
	for(int i=0;i<26;i++) {
		if(AC[0].ch[i]!=0) {
			AC[AC[0].ch[i]].fail=0;
			q.push(AC[0].ch[i]);
		}
	}
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++) {
			if(AC[u].ch[i]!=0) {
				AC[AC[u].ch[i]].fail=AC[AC[u].fail].ch[i];
				q.push(AC[u].ch[i]);
			}
			else 
			  AC[u].ch[i]=AC[AC[u].fail].ch[i];
		}
	}
}
int AC_work(string s) {
	int l=s.length();
	int now=0,ans=0;
	for(int i=0;i<l;i++) {
		now=AC[now].ch[index(s[i])];
		for(int j=now;j && AC[j].end!=-1;j=AC[j].fail) {
			ans+=AC[j].end;
			AC[j].end=-1;
		}
	}
	return ans;
}
int main() {
	int n;
	string s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		cin>>s;
		Build_Trie(s);
	}
	Get_fail();
	cin>>s;
	printf("%d",AC_work(s));
	return 0;
}
