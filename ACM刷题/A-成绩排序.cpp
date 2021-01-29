#include<stdio.h>
#include<string.h>
 typedef struct student
{
	char name[100];
	int score;
}stu;
stu s[100];
int main()
{
	char str1[100],name[100];
	int cnt=0,i,j,flag=0;
	scanf("%s",str1);
	while(strcmp(str1,"end")!=0)
	{
	if(strcmp(str1,"insert")==0)
	{
		scanf("%s %d",&s[cnt].name,&s[cnt].score);
		cnt++;
	}
	if(strcmp(str1,"find")==0)
	{
		scanf("%s",name);
		flag=0;
		for(i=0;i<cnt;i++)
		{
			if(strcmp(name,s[i].name)==0)
			{
				printf("%d\n",s[i].score);
				flag=1;
			}
		}
		if(flag==0) printf("-1\n");
	}
	scanf("%s",str1);
	}
	return 0;
}
