#include<stdio.h>
int main(){
    int i,j,n,k,t=0,d=0,temp,l;
    scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        temp=a[i][0];
        for(j=1;j<n;j++){
            if(temp<a[i][j])
                temp=a[i][j];
        }
        for(j=0;j<n;j++){
            if(a[i][j]==temp){
                t=0;
                l=j;
                for(k=0;k<n;k++){
                    if(a[k][l]<temp){
                        t++;
                    }
                }
                if(!t){
                    printf("%d %d",i,l);
                    d++;
                }
            }
        }
    }
    if(d==0) printf("NONE");
}
