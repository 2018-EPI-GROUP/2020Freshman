#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct student
{
	char name[25];//准考证号 
	int ac;//解题数量 
	int num[10];//
	int score;//总成绩 
};
bool cmp1(student &a, student &b)
{
	
	if (a.score == b.score) return strcmp(a.name, b.name) < 0 ? 1 : 0;//重要操作，考号升序 
	else return (a.score > b.score);//成绩由高到低 
}
int main()
{
	int N;
	while (scanf("%d", &N) != EOF&&N)
	{
		int M;//考生人数 
		int G;//分数线 
		int problem[15];//题目分数 
		scanf("%d %d", &M, &G);
		struct student stu[1000];
		int i, j, luqu=0;//录取人数，必须初始化！ 
		for (i = 1;i <= M;i++)
			scanf("%d", &problem[i]);
		for (i = 1;i <= N;i++)
		{
			scanf("%s %d", &stu[i].name, &stu[i].ac);
			stu[i].score=0;//注意：得分必须初始化！ 
			for (j = 1;j <= stu[i].ac;j++)
			{ 
				int temp=0;
				scanf("%d",&temp);//接受题号 
				stu[i].score = stu[i].score + problem[temp];//根据题号算得分	
			}
			if (stu[i].score >= G) luqu++;//大于等于就算过线 
		}
			sort(stu+1, stu + N+1, cmp1);//排序 
			printf("%d\n", luqu);
			for (i = 1;i <= luqu;i++)
				printf("%s %d\n", stu[i].name, stu[i].score);
	}	
	return 0;
}
