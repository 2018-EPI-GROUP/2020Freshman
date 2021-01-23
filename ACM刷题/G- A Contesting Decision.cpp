#include<stdio.h>
#include<string.h>
typedef struct pteam
{
	char name[30];
	int sub[4];//4道提交次数 
	int time[4];//4道提交时间 
	int ac,gtime;//解题数和总罚时 
}team;
int main()
{
	int n,i,j;
	char c_name[30];
	int c_ac=-1,c_gtime=99999999;
	scanf("%d",&n);
	team team_info[n];
	for(i=0;i<n;i++)
	{
		team_info[i].ac=0;team_info[i].gtime=0;
		scanf("%s",&team_info[i].name);
		for(j=0;j<4;j++) 
		{
			scanf("%d %d",&team_info[i].sub[j],&team_info[i].time[j]);
			if(team_info[i].time[j]>0) team_info[i].ac++;
			team_info[i].gtime=team_info[i].gtime+team_info[i].time[j];
			if(team_info[i].sub[j]>1&&team_info[i].time[j]!=0) 
			team_info[i].gtime=team_info[i].gtime+20*(team_info[i].sub[j]-1);
			if(team_info[i].ac>c_ac) 
			{
			strcpy(c_name,team_info[i].name);c_gtime=team_info[i].gtime;c_ac=team_info[i].ac;
			}
			else if(team_info[i].ac==c_ac)
			{
				if(team_info[i].gtime<c_gtime)
				{
					strcpy(c_name,team_info[i].name);c_gtime=team_info[i].gtime;
				}
			}	
		}
	}
	printf("%s %d %d\n",c_name,c_ac,c_gtime);
}
