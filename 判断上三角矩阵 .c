#include<stdio.h>
int main(){
    int i,t,b,c;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        int j,k,n;
        scanf("%d",&n);
        int a[n][n];
        b=1;c=1;
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                scanf("%d",&a[j][k]);
            }
        }
        for(j=1;j<n;j++){
            for(k=0;k<j;k++){
                if(a[j][k]!=0){
                    c=0;
                    break;
                }
            }
        }
        if(c) printf("YES\n");
        else printf("NO\n");
    }
}
