#include<stdio.h>
#include<string.h>
int main(){
    int i,t=0,k=1;
    char s[80],a[26];
    gets(s);
    for(i=0;i<strlen(s);i++){
        if(s[i]<='Z'&&s[i]>='A'){
            for(int j=0;j<t;j++){
                k=1;
                if(a[j]==s[i]){
                    k=0;
                    break;
                }
            }
            if(k){
                a[t]=s[i];
                t++;
            }
        }
    }
    if(t==0) printf("Not Found");
    else for(i=0;i<t;i++)
        printf("%c",a[i]);
}
