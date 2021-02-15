#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000005

using namespace std;

int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int fa[MAXN],cnt[MAXN],ch[MAXN][2],size[MAXN],val[MAXN],tot_size,root;

void clear(int x) {
	fa[x]=ch[x][0]=ch[x][1]=cnt[x]=size[x]=val[x]=0;
}

int get(int x) {
	return ch[fa[x]][1]==x;
}

void update(int x) {
	if(x) {
		size[x]=cnt[x];
		if(ch[x][0]) size[x]+=size[ch[x][0]];
		if(ch[x][1]) size[x]+=size[ch[x][1]];
	}
}

void rotate(int x) {
	int pa=fa[x],papa=fa[pa],which=get(x);
	ch[pa][which]=ch[x][!which];fa[ch[x][!which]]=pa;
	ch[x][!which]=pa;fa[pa]=x;
	fa[x]=papa;if(papa) ch[papa][ch[papa][1]==pa]=x;
	update(pa);update(x);
}

void splay(int x) {
	for(int f;f=fa[x];rotate(x)) {
		if(fa[f]) rotate(get(f)==get(x)?f:x);
	}
	root=x;
}

void insert(int v) {
	if(root==0) {
		tot_size++;
		ch[tot_size][0]=ch[tot_size][1]=fa[tot_size]=0;
		val[tot_size]=v;
		cnt[tot_size]=size[tot_size]=1;
		root=tot_size;
		return;
	}
	int f=0,now=root;
	while(true) {
		if(val[now]==v) {
			cnt[now]++;
			update(now);
			update(f);
			splay(now);
			return;
		}
		f=now;
		now=ch[now][val[now]<v];
		if(now==0) {
			tot_size++;
			ch[tot_size][0]=ch[tot_size][1]=0;
			fa[tot_size]=f;
			val[tot_size]=v;
			cnt[tot_size]=1,size[tot_size]=1;
			ch[f][val[f]<v]=tot_size;
			update(f);
			splay(tot_size);
			return;
		}
	}
}

int find(int x) {
	int res=0,now=root;
	while(true) {	
		if(x<val[now]) {
			now=ch[now][0];
		}
		else {
			res+=size[ch[now][0]];
			if(x==val[now]) {
				splay(now);
				return res+1;
			}
			res+=cnt[now];
			now=ch[now][1];
		}
	}
}

int findx(int p) {
	int now=root;
	while(true) {
		if(ch[now][0] && p<=size[ch[now][0]]) {
			now=ch[now][0];
		}
		else {
			int temp=size[ch[now][0]]+cnt[now];
			if(p<=temp) return val[now];
			p-=temp;
			now=ch[now][1];
		}
	}
}

int pre() {
	int now=ch[root][0];
	while(ch[now][1]) now=ch[now][1];
	return now;
}

int next() {
	int now=ch[root][1];
	while(ch[now][0]) now=ch[now][0];
	return now;
}

void del(int x) {
	int gg=find(x);
	if(cnt[root]>1) {
		cnt[root]--;
		return;
	}
	if(!ch[root][0] && !ch[root][1]) {
		clear(root);
		root=0;
		return;
	}
	if(!ch[root][0]) {
		int oldroot=root;
		root=ch[root][1];
		fa[root]=0;
		clear(oldroot);
		return;
	}
	else if(!ch[root][1]) {
		int oldroot=root;
		root=ch[root][0];
		fa[root]=0;
		clear(oldroot);
		return;
	}
	int oldroot=root;
	splay(pre());
	fa[ch[oldroot][1]]=root;
	ch[root][1]=ch[oldroot][1];
	clear(oldroot);
	update(root);
	return;
}

int main() {
	int n=read();
	while(n--) {
		int opt=read(),x=read();
		if(opt==1) insert(x);
		if(opt==2) del(x);
		if(opt==3) printf("%d\n",find(x));
		if(opt==4) printf("%d\n",findx(x));
		if(opt==5) {
			insert(x);
			printf("%d\n",val[pre()]);
			del(x);
		}
		if(opt==6) {
			insert(x);
			printf("%d\n",val[next()]);
			del(x);
		}
	}
	return 0;
}
