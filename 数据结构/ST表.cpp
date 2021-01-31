/*给定一个数列a，O(nlogn)预处理，O(1)查询数列在区间[l,r]的最值。
这里介绍求最大值。*/
int st[N][K],a[N],log_2[N];
inline void ini_st(){
    log_2[1]=0;
    for(int i=2;i<=n;++i){
        log_2[i]=log_2[i-1];
        if((1<<log_2[i]+1)==i)
            ++log_2[i];
    }
    for(int i=n;i;--i){
        st[i][0]=a[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
inline int ask(int l,int r){
    int k=log_2[r-l+1];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
