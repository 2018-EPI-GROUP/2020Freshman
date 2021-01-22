bool topsort() {
    queue<int>q;
    for(int i=1;i<=n;i++) if(du[i]==0) q.push(i);
    while(!q.empty()) {
        now=q.front();
        q.pop();
        k++;
        for(int i=p[now]; i!=-1; i=e[i].next) {
            go=e[i].to;
            du[go]--;
            if(du[go]==0)
                q.push(go);
        }
    }
    if(k==n) return true;
    else return false;
}
