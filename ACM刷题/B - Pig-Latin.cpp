#include<iostream>
#include<string.h>
int isyuan(char a[])
{
	if(a[0]=='a'||a[0]=='e'||a[0]=='i'||a[0]=='o'||a[0]=='u') return 1;
	if(a[0]=='A'||a[0]=='E'||a[0]=='I'||a[0]=='O'||a[0]=='U') return 1;
	return 0;
}
int iseng(char a[])
{
	if(a[0]>='A'&&a[0]<='Z') return 1;
	if(a[0]>='a'&&a[0]<='z') return 1;
	return 0;
}
int main()
{
	char a[100000];
	gets(a);
	if(!iseng(a)) puts(a);
	else if(isyuan(a))
	{
		printf("%s",a);
		printf("ay");
	}
	else
	{
		printf("%s%c",&a[1],a[0]);
		printf("ay");
	}
} 
