#include<stdio.h>
#include<string.h>
int main(){
    int i,j,t=1,count=0;
    char a[81],b[5]={'A','E','I','O','U'};
    gets(a);
    for(i=0;i<strlen(a);i++){
        t=1;
        if(a[i]>='A'&&a[i]<='Z'){
            for(j=0;j<5;j++){
                if(a[i]==b[j]){
                    t=0;break;
                }
            }
            if(t){
                count++;
            }
        }
   }
    printf("%d",count);
}
