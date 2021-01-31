//STL（用deque（双端队列））
#include <iostream>
#include <cstdio>
#include <queue>
#include <deque>

using namespace std;
typedef pair<int,int> P;
#define maxn 1000000 + 10

deque<P> Q1;
deque<P> Q2;
int n,k;
int Min[maxn], Max[maxn];

int main() {
    while(~scanf("%d%d", &n, &k)) {
        while(!Q1.empty()) Q1.pop_back();
        while(!Q2.empty()) Q2.pop_back();
        int x;
        for(int i=1; i<=n; i++) {
            scanf("%d", &x);
            while(!Q1.empty() && Q1.back().first >= x) Q1.pop_back();
            Q1.push_back(P(x,i));
            if(i >= k) {
                while(!Q1.empty() && Q1.front().second <= i-k) Q1.pop_front();
                Min[i] = Q1.front().first;
            }
            while(!Q2.empty() && Q2.back().first <= x) Q2.pop_back();
            Q2.push_back(P(x,i));
            if(i >= k) {
                while(!Q2.empty() && Q2.front().second <= i-k) Q2.pop_front();
                Max[i] = Q2.front().first;
            }
        }
        for(int i=k; i<=n; i++)
            i == n ? printf("%d\n", Min[i]) : printf("%d ", Min[i]);
        for(int i=k; i<=n; i++)
            i == n ? printf("%d\n", Max[i]) : printf("%d ", Max[i]);
    }
    return 0;
}

//手写
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 1000005

using namespace std;

struct s {
    int v,p;
    void f(int a,int b) {
        v=a,p=b;
    }
}Q1[MAXN],Q2[MAXN];

int h1,t1,h2,t2,Min[MAXN],Max[MAXN];
int n,k;

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        while(h1<t1 && Q1[t1].v>=x) t1--;
        Q1[++t1].f(x,i);
        if(i>=k) {
            while(h1<t1 && Q1[h1+1].p<=i-k) h1++;
            Min[i]=Q1[h1+1].v;
        }
        while(h2<t2 && Q2[t2].v<=x) t2--;
        Q2[++t2].f(x,i);
        if(i>=k) {
            while(h2<t2 && Q2[h2+1].p<=i-k) h2++;
            Max[i]=Q2[h2+1].v;
        }
    }
    for(int i=k;i<=n;i++) printf("%d ",Min[i]);
    printf("\n");
    for(int i=k;i<=n;i++) printf("%d ",Max[i]);
    return 0;
}
