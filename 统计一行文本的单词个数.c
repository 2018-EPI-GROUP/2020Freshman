#include<stdio.h>
#include<string.h>
int main(){
    int i,t=0;
    char str[1000];
    gets(str);
    for(i=0;i<strlen(str);i++){
        if(str[i]!=' '&&t==0) t++;
        else if(str[i]!=' '&&str[i-1]==' ') t++;
    }
    printf("%d",t);
}
