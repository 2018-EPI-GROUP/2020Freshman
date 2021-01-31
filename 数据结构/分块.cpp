//把问题分成许多（一般是根号n）块，在块中完成。时间复杂度为O（m根号n）
int belong[maxn],block,num,l[1000],r[1000];

int n,m;

void build() {
    block=sqrt(n);
    num=block;
    if(n%num)num++;
    for(int i=0;i<n;i++) {
        belong[i]=(i-1)/block;
    }
    for(int i=1;i<=num;i++) {
        l[i]=(i-1)*block;
        r[i]=i*block-1;
    }
    r[num]=n;
}
