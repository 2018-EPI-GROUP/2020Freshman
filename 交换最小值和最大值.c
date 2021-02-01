#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,t,a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int min=a[0];
    for(i=0;i<n;i++){
        if(a[i]<min){
            min=a[i];
            j=i;
        }
    }
    t=a[j];
    a[j]=a[0];
    a[0]=t;
    int max=a[n-1];
    for(i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
            j=i;
        }
    }
    t=a[j];
    a[j]=a[n-1];
    a[n-1]=t;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
