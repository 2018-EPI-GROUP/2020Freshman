void spfa(int s) {
for(int i=0;i<=10010;i++)dist[i]=2147483647;
queue<int> q;
dist[s]=0;
vis[s]=1;
q.push(s);
while(!q.empty()) {
    int u=q.front();
    q.pop();
    vis[u]=0;
    for(int i=head[u];i;i=e[i].next) {
        int to=e[i].to;
        if(dist[to]>dist[u]+e[i].cost) {
            dist[to]=dist[u]+e[i].cost;
            if(!vis[to]) {
                vis[to]=1;
                q.push(to);
            }
        }
    }
}
}
