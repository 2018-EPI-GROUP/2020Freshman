#include<stdio.h>
#include<string.h>
int main(){
    int i,n;
    scanf("%d",&n);
    getchar();
    char str[8000][80],t[80];
    for(i=0;i<n;i++){
        gets(str[i]);
    }
    for(i=1;i<n;i++){
        if(strcmp(str[0],str[i])>0){
            strcpy(t,str[0]);
            strcpy(str[0],str[i]);
            strcpy(str[i],t);
            }
    }
    printf("Min is: %s",str[0]);
}
