int find(int x) {
    if(fa[x]!=x) return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
    fa[find(x)]=fa[find(y)];
}
