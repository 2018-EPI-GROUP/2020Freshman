#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
	 	char str[200];
	 	gets(str);
	 	int m,a=0,e=0,i=0,o=0,u=0;
	 	for(m=0;str[m]!='\0';m++) 
	 	{
	 		switch(str[m])
	 		{
	 			case'a':a++;break;
	 			case'e':e++;break;
	 			case'i':i++;break;
	 			case'o':o++;break;
	 			case'u':u++;break;
			}
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u);
		if(n!=0) printf("\n");	
	}
	return 0; 
}
