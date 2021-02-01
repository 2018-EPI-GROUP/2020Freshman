#include<stdio.h>
main(){
    int i,n,max=0;
    int number[10]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        if(a==0) number[0]++;
        while(a>0){
            number[a%10]++;
            a/=10;
        }
    }
    for(i=0;i<10;i++){
        if(number[i]>max){
            max=number[i];
        }
    }printf("%d:",max);
    for(i=0;i<10;i++){
        if(number[i]==max)
            printf(" %d",i);
    }
    return 0;
}
