#include<stdio.h>
int main(){
    int i,j,k=0,n,count=0,temp=1;
    scanf("%d",&n);
    int a[1000],b[1000],c[1000]={0};
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        temp=1;
        for(j=0;j<count;j++){
            if(a[i]==b[j]){
                c[j]++;
                temp=0;
                break;
            }
        }
        if(temp){
            b[count]=a[i];
            c[count]++;
            count++;
        }
    }
    int max=c[0];
    for(i=0;i<count;i++){
        if(c[i]>max){
            max=c[i];
            k=i;
        }
    }
    printf("%d %d",b[k],c[k]);
}
