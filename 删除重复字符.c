#include <stdio.h>
#include<stdio.h>
int main( )
{
	int i,j,k=0,flag=1;
	char str[80],ch[80],t;
    gets(str);
	for(i=0;str[i]!='\0';i++){
		flag=1;
		for(j=0;j<i;j++){
			if(str[i]==str[j]){
				flag=0;
				break;
			}
		}
		if(flag){
			ch[k]=str[i];
			k++;
		}
	}
	ch[k]='\0';
	for(i=0;i<k-1;i++){
		for(j=i+1;j<k;j++){
			if(ch[i]>ch[j]){
				t=ch[i];ch[i]=ch[j];ch[j]=t;
			}
		}
	}
	puts(ch);
	return 0;
}
