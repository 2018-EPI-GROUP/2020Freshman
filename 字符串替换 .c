#include<stdio.h>
#include<string.h>
int main(){
    int i;
    char str[81];
    gets(str);
    for(i=0;i<strlen(str);i++){
        if(str[i]>='A'&&str[i]<='Z') str[i]=155-str[i];
    }
    puts(str);
}
