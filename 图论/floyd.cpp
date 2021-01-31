void floyd() {
memset(dist,0x3f,sizeof(dist));
memset(map,0x3f,sizeof(map));
for(int k=1;k<=n;k++) 
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++) {
    dist[i][j]=min(map[i][j],map[i][k]+map[k][j]);
}
}
