#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 1000005
#define ll long long
using namespace std;
inline ll read() {
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[maxn],sum[maxn<<2],col[maxn<<2];
void updata(ll rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void color(ll l,ll r,ll rt,ll c) {
    col[rt]+=c;
    sum[rt]+=c*(r-l+1);
}
void push_col(ll l,ll r,ll rt) {
    if(col[rt]) {
        ll m=(l+r)>>1;
        color(lson,col[rt]);
        color(rson,col[rt]);
        col[rt]=0;
    }
}
void build(ll l,ll r,ll rt) {
    if(l==r) {
        sum[rt] = a[l];
        return ;
    }
    ll m=(l+r)>>1;
    build(lson);
    build(rson);
    updata(rt);
}
ll query(ll l,ll r,ll rt,ll L,ll R) {
    if(L<=l && R>=r)return sum[rt];
    push_col(l,r,rt);
    ll ret=0;
    ll m=(l+r)>>1;
    if(L<=m) ret+=query(lson,L,R);
    if(m<R) ret+=query(rson,L,R);
    return ret;
}
void modify(ll l,ll r,ll rt,ll L,ll R,ll v) {
    if(L<=l && R>=r) {
        color(l,r,rt,v);
        return ;
    }
    push_col(l,r,rt);
    ll m=(l+r)>>1;
    if(L<=m) modify(lson,L,R,v);
    if(m<R) modify(rson,L,R,v);
    updata(rt);
}
ll n,m;
int main() {
    n=read(),m=read();
    for(ll i=1;i<=n;i++)a[i]=read();
    build(1,n,1);
    while(m--) {
        ll id=read();
        if(id==2) {
            ll x=read(),y=read();
            printf("%lld\n",query(1,n,1,x,y));
        }
        else {
            ll x=read(),y=read(),z=read();
            modify(1,n,1,x,y,z);
        }
    }
    return 0;
}
