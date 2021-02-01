#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,j=0,t,a[n+1];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int x;
    scanf("%d",&x);
    for(i=0;i<n;i++){
        if(x<a[i]){
            j=i;
            break;
        }
        if(x>=a[n-1]) j=n;
    }
    for(i=n;i>j;i--){
        a[i]=a[i-1];
    }
    a[j]=x;
    for(i=0;i<n+1;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
