#include<stdio.h>
#include<string.h>
int main(){
    int i=0,j=0;
    char str[5][80],t[80];
    for(i=0;i<5;i++){
        scanf("%s",str[i]);
    }
    for(i=0;i<4;i++){
        for(j=i+1;j<5;j++)
            if(strcmp(str[i],str[j])>0){
                strcpy(t,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],t);
                }
    }
    printf("After sorted:\n");
    for(i=0;i<5;i++){
        puts(str[i]);
    }
}
