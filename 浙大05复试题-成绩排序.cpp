#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct student
{
	char name[25];//׼��֤�� 
	int ac;//�������� 
	int num[10];//
	int score;//�ܳɼ� 
};
bool cmp1(student &a, student &b)
{
	
	if (a.score == b.score) return strcmp(a.name, b.name) < 0 ? 1 : 0;//��Ҫ�������������� 
	else return (a.score > b.score);//�ɼ��ɸߵ��� 
}
int main()
{
	int N;
	while (scanf("%d", &N) != EOF&&N)
	{
		int M;//�������� 
		int G;//������ 
		int problem[15];//��Ŀ���� 
		scanf("%d %d", &M, &G);
		struct student stu[1000];
		int i, j, luqu=0;//¼ȡ�����������ʼ���� 
		for (i = 1;i <= M;i++)
			scanf("%d", &problem[i]);
		for (i = 1;i <= N;i++)
		{
			scanf("%s %d", &stu[i].name, &stu[i].ac);
			stu[i].score=0;//ע�⣺�÷ֱ����ʼ���� 
			for (j = 1;j <= stu[i].ac;j++)
			{ 
				int temp=0;
				scanf("%d",&temp);//������� 
				stu[i].score = stu[i].score + problem[temp];//���������÷�	
			}
			if (stu[i].score >= G) luqu++;//���ڵ��ھ������ 
		}
			sort(stu+1, stu + N+1, cmp1);//���� 
			printf("%d\n", luqu);
			for (i = 1;i <= luqu;i++)
				printf("%s %d\n", stu[i].name, stu[i].score);
	}	
	return 0;
}
