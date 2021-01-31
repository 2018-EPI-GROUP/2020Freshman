int comp(E a,E b) {
    return a.v<b.v;
}

int find(int x) {
    if(fa[x]!=x) return fa[x]=find(fa[x]);
}

void merge(int x,int y) {
    fa[find(x)]=fa[find(y)];
}

void Kruskal() {
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(e+1,e+1+m,comp);
    for(int i=1,k=0;i<=m;i++) {
        if(find(e[i].x) != find(e[i].y)) {
            merge(e[i].x,e[i].y);
            k++;
            tot+=e[i].v;
        }
        if(k == n-1) {
            cout<<tot;
            return ;
        }
    }
    cout<<"orz";
}
