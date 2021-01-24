#include<stdio.h>
int main(){
    int a,b,c,s=0,i;
    scanf("%d/%d/%d",&a,&b,&c);
    int d[12];
    for(i=0;i<b-1;i++){
        if(i==1){
            if((a%4==0&&a%100!=0)||a%400==0){
                d[i]=29;
            }else
                d[i]=28;
        }else if(i==0||i==2||i==4||i==6||i==7||i==9||i==11){
                d[i]=31;
        }else if(i==3||i==5||i==8||i==10){
                d[i]=30;
        }
    }
    for(i=0;i<b-1;i++)
        s+=d[i];
    printf("%d",s+c);
}
