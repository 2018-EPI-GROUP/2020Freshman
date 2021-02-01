#include<stdio.h>
#include<string.h>
int main(){
    int i,t=0,sum=0,f=0;
    char s[1000];
    gets(s);
    for(i=0;i<strlen(s);i++){
        if(t==0&&s[i]=='-'){
            f=1;
            t++;
        }
        if(s[i]>='0'&&s[i]<='9'){
            sum=sum*16+s[i]-48;
            t++;
        }
        if(s[i]>='A'&&s[i]<='F'){
            sum=sum*16+s[i]-55;
            t++;
        }
        if(s[i]>='a'&&s[i]<='f'){
            sum=sum*16+s[i]-87;
            t++;
        }
    }
    if(!sum) 
        printf("0");
    else if(f) 
        printf("-");
    if(sum) 
        printf("%d",sum);
}
