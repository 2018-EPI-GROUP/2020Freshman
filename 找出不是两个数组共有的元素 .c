#include<stdio.h>
main(){
    int i,j,n1,n2,t,a[20],b[20];
    scanf("%d",&n1);
    for(i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&n2);
    for(i=0;i<n2;i++){
        scanf("%d",&b[i]);
    }
    int count=0,c[40];
    for(j=0;j<n1;j++){
        t=1;
        for(i=0;i<n2;i++){
            if(a[j]==b[i]){
                t=0;break;
            }
        }
        if(t){
            int h,y=1;
            for(h=0;h<count;h++){
                if(c[h]==a[j]){
                    y=0;break;
                }
            }
            if(y){
                c[count]=a[j];
                count++;
            }
        }
    }
    for(j=0;j<n2;j++){
        t=1;
        for(i=0;i<n1;i++){
            if(b[j]==a[i]){
                t=0;break;
            }
        }
        if(t){
            int h,y=1;
            for(h=0;h<count;h++){
                if(c[h]==b[j]){
                    y=0;break;
                }
            }
            if(y){
                c[count]=b[j];
                count++;
            }
        }
    }
    for(i=0;i<count;i++){
        printf("%d",c[i]);
        if(i<count-1) printf(" ");
    }
}
