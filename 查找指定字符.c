#include<stdio.h>
int main(){
    int i=0,j=0,t=-1;
    char c,ch,s[80];
    scanf("%c",&c);
    ch=getchar();
    ch=getchar();
    while(ch!='\n'){
        s[i]=ch;
        if(c==s[i])
            t=i;
        ch=getchar();
        i++;
    }
    if(t==-1) printf("Not Found");
    else printf("index = %d",t);
}
