#include<stdio.h>
#include<string.h>
int main(){
    int i,t=0;
    char str[81];
    gets(str);
    for(i=0;i<strlen(str);i++){
        if(str[i]>='0'&&str[i]<='9')
            t=t*10+str[i]-48;
    }
    printf("%d",t);
}
