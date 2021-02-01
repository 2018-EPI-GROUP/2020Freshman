#include<stdio.h>
int main(){
    int m,n,i,j,k,t,a[6][6];
    scanf("%d %d",&m,&n);
    m=m%n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(k=0;k<m;k++)
            for(j=n-1;j>0;j--){
                t=a[i][j];
                a[i][j]=a[i][j-1];
                a[i][j-1]=t;
        }
    }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d ",a[i][j]);
            }printf("\n");
        }
}
