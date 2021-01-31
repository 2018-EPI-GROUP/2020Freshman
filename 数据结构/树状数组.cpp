/*
1.将某一个数加上x
2.求出某区间每一个数的和
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 500005

using namespace std;

int a[MAXN],c[MAXN],n,m;

int lowbit(int x) {
    return x&(-x);
}

void modify(int p,int x) {
    while(p<=n) {
        c[p]+=x;
        p+=lowbit(p);
    }
    return ;
}

int sum(int p) {
    int sum=0;
    while(p) {
        sum+=c[p];
        p-=lowbit(p);
    }
    return sum;
}

int query(int l,int r) {
    return sum(r)-sum(l-1);
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),modify(i,a[i]);
    for(int i=1;i<=m;i++) {
        int id,x,y;
        scanf("%d%d%d",&id,&x,&y);
        if(id==1) modify(x,y); 
        else printf("%d\n",query(x,y));
    }
    return 0;
}

/*
1.将某区间每一个数数加上x
2.求出某一个数的和
*/
#include <iostream>
#include <cstdio>
#define maxn 500000+5

using namespace std;

int n,m,pre,c[maxn];

int lowbit(int x) {
    return x&(-x);
}

void modify(int pos,int x) {
    while(pos<=n) {
        c[pos]+=x;
        pos+=lowbit(pos);
    }
    return ;
}

int query(int pos) {
    int ans=0;
    while(pos>0) {
        ans+=c[pos];
        pos-=lowbit(pos);
    }
    return ans;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        int x;
        scanf("%d",&x);
        modify(i,x-pre);
        pre=x;
    }
    while(m--) {
        int id;
        scanf("%d",&id);
        if(id==1) {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            modify(l,k);
            modify(r+1,-k);
        } else {
            int pos;
            scanf("%d",&pos);
            printf("%d\n",query(pos));
        }
    }
    return 0;
}
