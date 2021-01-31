bool dfs(int now) {
    for (int a=1; a<=m; a++)
        if (match[now][a] && !use[a]) {
            use[a]=true;
            if (!result[a] || dfs(result[a])) {
                result[a]=now;
                return true;
            }
        }
    return false;
}
void xiongyali() {
    int ans=0;
    for (int a=1; a<=n; a++) {
        memset(use,false,sizeof(use));
        if (dfs(a)) ans++;
    }
}
