void dfs(int x) {
DFN[x]=++Time;
LOW[x]=DFN[x];
st[++r]=x;
int R=r;
V[x]=true;
for (int i=0; i<v[x].size(); i++)
    if (v[x][i]!=fa[x]) {
        fa[v[x][i]]=x;
        if (!DFN[v[x][i]]) {
            dfs(v[x][i]);
            LOW[x]=min(LOW[x],LOW[v[x][i]]);
        } else if (V[v[x][i]]) LOW[x]=min(LOW[x],DFN[v[x][i]]);
    }
if (LOW[x]==DFN[x]) {
    cnt++;
    for (int i=R; i<=r; i++) {
        p[st[i]]=cnt;
        V[st[i]]=false;
    }
    r=R-1;
}
}
