int lca(int x,int y) {
if(deep[x]>deep[y]) swap(x,y);
for(int i=20; i>=0; i--) {
    if(deep[fa[y][i]]>=deep[x]) y=fa[y][i];   
}
if(x==y)return x;
for(int i=20; i>=0; i--) {
    if(fa[x][i]!=fa[y][i]) {
        x=fa[x][i],y=fa[y][i];   
    }
}
return fa[x][0];
}
void dfs(int x) {
deep[x]=deep[fa[x][0]]+1;
for(int i=0; fa[x][i]; i++)
    fa[x][i+1]=fa[fa[x][i]][i];
for(int i=0; i<vec[x].size(); i++)
    if(!deep[vec[x][i]]) {
        fa[vec[x][i]][0]=x;   
        dfs(vec[x][i]);
    }
}
