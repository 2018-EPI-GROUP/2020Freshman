# project

```
#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h> 
#include<conio.h>
#include<time.h>
#define P 20
#define N 20
#define S 10
#define B 5

struct PASS
{
	char ID[15];//登录账号
	char password[20];//登录密码
};//登录账号和密码
struct People
{
	char name[P];
	char number[N];
	int age;
	char sex[S];
}; //任务信息
struct PEO
{
	struct People* people;
	int size;
	int Bigsize;
};//嵌套任务信息和存储人数
struct PEO Peo;

enum Option
{
	Display = 1,
	Input,
	Del,
	Mod,
	Query,
	sort,
	save,
	Exit
};

int Pass();//登录系统
void SetPosition(int x, int y);//设置坐标
void biankuang();//设置边框
void menu();//设置菜单选项
void clean();//清屏
void zhuce();//注册账号
void InitPeo(struct PEO* p);//初始化通讯录
void Checksize(struct PEO* p);//检查通讯录内存
void InputPeo(struct  PEO* p);//增加联系人信息
void DisplayPeo(struct PEO* p);//显示联系人列表
void Delate(struct PEO* p);//删除联系人
void ModifyPeo(struct PEO* p);//修改联系人
int  Return(struct PEO* p, char name[N]);//返回查找下标或者返回失败的-1
void DistroMemory(struct PEO* p);//释放动态内存所分配的空间
void QueryPeo(struct PEO* p);//查询联系人
void SavePeo(struct PEO* p);//保存练习人
void SaveShow(struct PEO* p);//保存文件中的联系人到通讯录
void JudgeSystem(int num);//判断系统是否可以正确登录
void JudgeSystem2(int num);//判断系统等待时间
void JudgeSystem3(int num);//判断系统是否锁定
int ReadSystem();//读取判断系统中的数字
int ReadSystem2();//读取判断系统中的分钟
int ReadSystem3();//如果锁定读出1
void GetTime();//获取系统时间
void Sort(struct PEO* p, int size);//排序

int main()
{
	int input = 0;
	int t = 0;
	biankuang();
	t = Pass();
	if (t == -1)
	{
		return;
	}
	SetPosition(55, 19);
	GetTime();
	InitPeo(&Peo);
	while (1)
	{
		menu();
		SetPosition(55, 19);
		GetTime();
		SetPosition(70, 14);
		printf("请做出你的选择：");
		SetPosition(86, 14);
		scanf("%d", &input);

		switch (input)
		{
		case Display:
			clean();
			SetPosition(55, 19);
			GetTime();
			DisplayPeo(&Peo);
			getch();
			clean();
			break;
		case Input:
			clean();
			SetPosition(55, 19);
			GetTime();
			InputPeo(&Peo);
			clean();
			break;
		case Del:
			clean();
			SetPosition(55, 19);
			GetTime();
			Delate(&Peo);
			clean();
			break;
		case Mod:
			clean();
			SetPosition(55, 19);
			GetTime();
			ModifyPeo(&Peo);
			clean();
			break;
		case Query:
			clean();
			SetPosition(55, 19);
			GetTime();
			QueryPeo(&Peo);
			clean();
			break;
		case sort:
			clean();
			SetPosition(55, 19);
			GetTime();
			Sort(&Peo, Peo.size);

			clean();
			break;
		case save:

			clean();
			SetPosition(55, 19);
			GetTime();
			SavePeo(&Peo);
			clean();
			break;
		case Exit:
			DistroMemory(&Peo);
			clean();
			SetPosition(55, 19);
			GetTime();
			SetPosition(65, 2);
			printf("正在为您销毁动态内存空间，请稍后");
			Sleep(700);
			clean();
			SetPosition(55, 19);
			GetTime();
			SetPosition(65, 2);
			printf("销毁成功");
			getch();
			return;
			break;
		default:
			SetPosition(76, 15);
			printf("你的输入有误，请重新输入");
			SetPosition(55, 19);
			GetTime();
			getch();
			clean();

		}

	}
	system("pause");
}

void SetPosition(int x, int y)
{
	HANDLE winHandle;
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(winHandle, pos);
}

void biankuang()
{
	SetPosition(10, 0);
	printf(" --------------------------------------------------------------------------------------------------- ");
	SetPosition(10, 1);
	printf("|");
	SetPosition(10, 2);
	printf("|");
	SetPosition(10, 3);
	printf("|");
	SetPosition(10, 4);
	printf("|");
	SetPosition(10, 5);
	printf("|");
	SetPosition(10, 6);
	printf("|");
	SetPosition(10, 7);
	printf("|");
	SetPosition(10, 8);
	printf("|");
	SetPosition(10, 9);
	printf("|");
	SetPosition(10, 10);
	printf("|");
	SetPosition(10, 11);
	printf("|");
	SetPosition(10, 12);
	printf("|");
	SetPosition(10, 13);
	printf("|");
	SetPosition(10, 14);
	printf("|");
	SetPosition(10, 15);
	printf("|");
	SetPosition(10, 16);
	printf("|");
	SetPosition(10, 17);
	printf("|");
	SetPosition(10, 18);
	printf("|");
	SetPosition(10, 19);
	printf("|");
	SetPosition(10, 20);
	printf("|");
	SetPosition(10, 20);
	printf(" --------------------------------------------------------------------------------------------------- ");
	SetPosition(110, 1);
	printf("|");
	SetPosition(110, 2);
	printf("|");
	SetPosition(110, 3);
	printf("|");
	SetPosition(110, 4);
	printf("|");
	SetPosition(110, 5);
	printf("|");
	SetPosition(110, 6);
	printf("|");
	SetPosition(110, 7);
	printf("|");
	SetPosition(110, 8);
	printf("|");
	SetPosition(110, 9);
	printf("|");
	SetPosition(110, 10);
	printf("|");
	SetPosition(110, 11);
	printf("|");
	SetPosition(110, 12);
	printf("|");
	SetPosition(110, 13);
	printf("|");
	SetPosition(110, 14);
	printf("|");
	SetPosition(110, 15);
	printf("|");
	SetPosition(110, 16);
	printf("|");
	SetPosition(110, 17);
	printf("|");
	SetPosition(110, 18);
	printf("|");
	SetPosition(110, 19);
	printf("|");
	SetPosition(110, 20);
	printf("|");
	SetPosition(11, 1);
	printf("                       *");
	SetPosition(11, 2);
	printf("                    *      *");
	SetPosition(11, 3);
	printf("                  *           *");
	SetPosition(11, 4);
	printf("               *                 *");
	SetPosition(11, 5);
	printf("            *  *  *  *  *  *  *  *  *");
	SetPosition(11, 6);
	printf("                  *           *");
	SetPosition(11, 7);
	printf("               *                 *");
	SetPosition(11, 8);
	printf("            *                       *");
	SetPosition(11, 9);
	printf("         *                             *");
	SetPosition(11, 10);
	printf("      *  *  *  *  *  *  *  *  *  *  *  *  *");
	SetPosition(11, 11);
	printf("                    *        *");
	SetPosition(11, 12);
	printf("                    *        *");
	SetPosition(11, 13);
	printf("                    *        *");
	SetPosition(11, 14);
	printf("                    *        *");
	SetPosition(11, 15);
	printf("                    *        *");
	SetPosition(11, 16);
	printf("                    *        *");
	SetPosition(11, 17);
	printf("                    *        *");
	SetPosition(11, 18);
	printf("                    *  *  *  *");





}

void menu()
{
	clean();
	SetPosition(70, 6);
	printf("1、查看联系人列表");
	SetPosition(90, 6);
	printf("2、增加联系人");
	SetPosition(70, 8);
	printf("3、删除联系人");
	SetPosition(90, 8);
	printf("4、修改联系人信息");
	SetPosition(70, 10);
	printf("5、查询联系人信息");
	SetPosition(90, 10);
	printf("6、联系人排序");
	SetPosition(70, 12);
	printf("7、保存联系人信息");
	SetPosition(90, 12);
	printf("8、退出通讯录");
	SetPosition(10, 21);
}

void clean()
{

	SetPosition(55, 1);
	printf("                                                       ");
	SetPosition(55, 2);
	printf("                                                       ");
	SetPosition(55, 3);
	printf("                                                       ");
	SetPosition(55, 4);
	printf("                                                       ");
	SetPosition(55, 5);
	printf("                                                       ");
	SetPosition(55, 6);
	printf("                                                       ");
	SetPosition(55, 7);
	printf("                                                       ");
	SetPosition(55, 8);
	printf("                                                       ");
	SetPosition(55, 9);
	printf("                                                       ");
	SetPosition(55, 10);
	printf("                                                       ");
	SetPosition(55, 11);
	printf("                                                       ");
	SetPosition(55, 12);
	printf("                                                       ");
	SetPosition(55, 13);
	printf("                                                       ");
	SetPosition(55, 14);
	printf("                                                       ");
	SetPosition(55, 15);
	printf("                                                       ");
	SetPosition(55, 16);
	printf("                                                       ");
	SetPosition(55, 17);
	printf("                                                       ");
	SetPosition(55, 18);
	printf("                                                       ");
	SetPosition(55, 19);
	printf("                                                       ");



	SetPosition(10, 21);
}

int Pass()
{
	int count = 0;
	int MIN;
	int Min;
	int temp = ReadSystem();
	int judge = temp;
	char id[20];
	char password[15];
	struct PASS dl = { "123456","123456" };
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);

	Min = ReadSystem2();
	if (Min <= p->tm_min && judge == 5)
	{
		count == 0;
		JudgeSystem3(count);
		judge = 0;
	}
	count = ReadSystem3();
	if (count == 1)
	{
		SetPosition(65, 10);
		printf("系统锁定中········");
		getch();
		return -1;
	}
	clean();

Second:
	if (judge == 5)
	{
		clean();
		SetPosition(65, 10);
		printf("连续五次账号或密码错误，系统锁定");
		SetPosition(65, 11);
		MIN = p->tm_min + 3;
		JudgeSystem2(MIN);
		printf("请在%d时%d分后再次进入", 8 + p->tm_hour, p->tm_min + 3);
		count = 1;
		JudgeSystem3(count);
		getch();
		return -1;
	}
	SetPosition(70, 5);
	printf("通讯录登录系统");


	SetPosition(60, 8);
	printf("请输入登录账号：");
	SetPosition(60, 12);
	printf("请输入你的密码：");

	SetPosition(76, 8);
	scanf("%s", &id);


	SetPosition(76, 12);
	scanf("%s", &password);



	if (strcmp(id, dl.ID) == 0 && strcmp(password, dl.password) == 0)
	{
		clean();
		SetPosition(70, 10);
		printf("登录成功");
		judge = 0;
		JudgeSystem(judge);
		Sleep(500);
		clean();
		menu();
		return 1;
	}
	else
	{
		clean();
		SetPosition(70, 10);
		printf("账号或者密码错误，请重新登陆");
		judge++;
		JudgeSystem(judge);
		getch();
		clean();
		goto Second;

	}

}

void Checksize(struct PEO* p)
{
	if (p->size == p->Bigsize)
	{
		struct People* ptr = realloc(p->people, (p->Bigsize + 5) * sizeof(struct People));//为内存中增加5个容量
		if (ptr != NULL)
		{
			p->people = ptr;
			p->Bigsize += 5;

		}
	}
}

void SaveShow(struct PEO* p)
{

	struct People tem = { 0 };
	FILE* fpp = fopen("List.txt", "rb");
	if (fpp == NULL)
	{
		clean();

		SetPosition(65, 5);
		printf("SaveShow::%s", strerror(errno));
		return;
	}
	while (fread(&tem, sizeof(struct People), 1, fpp) != 0)
	{
		Checksize(p);
		p->people[p->size] = tem;
		p->size++;

	}
	fclose(fpp);
	fpp = NULL;
}

void InitPeo(struct PEO* p)
{

	p->people = (struct People*)malloc(B * sizeof(struct People));
	if (p->people == NULL)
	{
		return;
	}

	p->size = 0;
	p->Bigsize = B;
	SaveShow(p);
}

void InputPeo(struct PEO* p)
{
	Checksize(p);//检查通讯录当前内存，如果满了则啥都不干，如果没满，则增加内存

	SetPosition(65, 2);
	printf("请输入联系人姓名：");
	SetPosition(82, 2);
	scanf("%s", p->people[p->size].name);
	SetPosition(65, 4);
	printf("请输入联系人电话：");
	SetPosition(82, 4);
	scanf("%s", p->people[p->size].number);
	SetPosition(65, 6);
	printf("请输入联系人性别：");
	SetPosition(82, 6);
	scanf("%s", p->people[p->size].sex);
	SetPosition(65, 8);
	printf("请输入联系人年龄：");
	SetPosition(82, 8);
	scanf("%d", &p->people[p->size].age);
	SetPosition(65, 10);
	printf("添加成功");
	getch();
	p->size++;

}

void DistroMemory(struct PEO* p)
{
	free(p->people);
	p->people = NULL;
}

void DisplayPeo(struct PEO* p)
{

	if (p->size == 0)
	{
		SetPosition(65, 10);
		printf("你的联系人列表为空");
	}
	else
	{
		int i;
		SetPosition(65, 1);
		printf("%-10s%-13s%-8s%-5s", "姓名", "电话", "性别", "年龄");
		for (i = 0; i < p->size; i++)
		{

			SetPosition(65, i + 2);

			printf("%-10s%-13s%-8s%-5d", p->people[i].name, p->people[i].number, p->people[i].sex, p->people[i].age);

		}
	}
}

void Delate(struct PEO* p)
{
	char tname[N];
	int i;
	int j;
	int choice;
	int text = 1;
	if (p->size == 0)
	{
		SetPosition(65, 2);
		printf("你的联系人列表为空");
		getch();
	}
	else
	{
		SetPosition(65, 2);
		printf("请在下方输入你要删除联系人的姓名：");
		SetPosition(65, 3);
		scanf("%s", tname);
		for (i = 0; i < p->size; i++)
		{
			if (strcmp(tname, p->people[i].name) == 0)
			{
				SetPosition(65, 4);
				printf("请确认是否要删除%s", tname);
				SetPosition(65, 5);
				printf("1、是       2、否");
				while (text)
				{
					SetPosition(65, 6);
					scanf("%d", &choice);
					if (choice == 1)
					{
						for (j = i; j < p->size - 1; j++)
						{
							p->people[j] = p->people[j + 1];
						}
						SetPosition(65, 7);
						printf("删除成功");
						getch();
						p->size--;
						text = 0;
					}
					else if (choice == 2)
					{
						SetPosition(65, 7);
						printf("你已经取消删除");
						getch();
						text = 0;
					}
					else
					{
						SetPosition(65, 7);
						printf("你的输入有误，请重新输入");
						getch();
						SetPosition(55, 6);
						printf("                                                       ");
						SetPosition(55, 7);
						printf("                                                       ");
					}
				}
				break;
			}
		}
		if (i == p->size)
		{
			SetPosition(65, 4);
			printf("你要删除的联系人不存在");
			getch();
		}

	}

}

void ModifyPeo(struct PEO* p)
{
	int temp2 = 0;
	int temp3 = 0;
	char name2[N];
	int temp = -1;
First:
	SetPosition(65, 2);
	printf("请输入你要修改联系人的姓名：");
	SetPosition(65, 3);
	scanf("%s", &name2);
	temp = Return(p, name2);
	if (temp != -1)
	{
		SetPosition(65, 4);
		printf("请输入修改后姓名：");
		scanf("%s", p->people[temp].name);
		SetPosition(65, 5);
		printf("请输入修改后电话：");
		scanf("%s", p->people[temp].number);
		SetPosition(65, 6);
		printf("请输入修改后性别：");
		SetPosition(65, 7);
		scanf("%s", p->people[temp].sex);
		SetPosition(65, 8);
		printf("请输入修改后年龄：");
		SetPosition(65, 9);
		scanf("%d", &p->people[temp].age);
	}
	else
	{
		SetPosition(65, 4);
		printf("该联系人不存在");
		SetPosition(65, 5);
		printf("您可以按1键查看您的通讯录列表(非0键退出)");
		scanf("%d", &temp2);
		if (temp2 == 1)
		{
			clean();
			DisplayPeo(p);
			getch();
			clean();
			SetPosition(65, 2);
			printf("请问您是否要继续修改？");
			SetPosition(65, 3);
			printf("（按1继续，按0退出到主界面）");
			scanf("%d", &temp3);
			if (temp3 == 1)
			{
				clean();
				goto First;
			}
			else
			{
				clean();
				SetPosition(65, 2);
				printf("正在为您退出主界面·    ");
				Sleep(400);
				SetPosition(65, 2);
				printf("                        ");
				SetPosition(65, 2);
				printf("正在为您退出主界面··  ");
				Sleep(600);
				SetPosition(65, 2);
				printf("                        ");
				SetPosition(65, 2);
				printf("正在为您退出主界面···");
				Sleep(600);


			}
		}
	}


}

int Return(struct PEO* p, char name[N])
{
	int i;
	if (p->size == 0)
	{
		SetPosition(65, 2);
		return -1;
	}
	else
	{
		for (i = 0; i < p->size; i++)
		{
			if (strcmp(name, p->people[i].name) == 0)
			{
				return i;
			}
		}

	}
	return -1;

}

void QueryPeo(struct PEO* p)
{
	int queryname[N];
	int judge = 0;
	SetPosition(65, 2);
	printf("请输入你要查询联系人的姓名：");
	SetPosition(65, 3);
	scanf("%s", queryname);
	judge = Return(p, queryname);
	if (judge != -1)
	{
		SetPosition(65, 4);
		printf("查询成功,正在为您载入,请稍后…");
		SetPosition(65, 5);
		Sleep(400);
		printf("■■■                   30%%");
		Sleep(500);
		SetPosition(65, 5);
		printf("                 ");
		SetPosition(65, 5);
		printf("■■■■■■■           70%%");
		Sleep(600);
		SetPosition(65, 5);
		printf("                 ");
		SetPosition(65, 5);
		printf("■■■■■■■■■■    100%%");
		Sleep(600);
		SetPosition(65, 4);
		printf("                                         ");
		SetPosition(65, 5);
		printf("                                         ");
		SetPosition(65, 4);
		printf("%-10s%-13s%-8s%-5s", "姓名", "电话", "性别", "年龄");
		SetPosition(65, 5);
		printf("%-10s%-13s%-8s%-5d", p->people[judge].name, p->people[judge].number, p->people[judge].sex, p->people[judge].age);
		getch();
	}
	else
	{
		SetPosition(65, 4);
		printf("该联系人不在您的通讯录中");
		getch();
	}
}

void SavePeo(struct PEO* p)
{
	int i;
	FILE* PeopleList = fopen("List.txt", "wb");
	if (PeopleList == NULL)
	{
		SetPosition(65, 2);
		printf("SavePeo::%s", strerror(errno));

		return;
	}
	else
	{
		for (i = 0; i < p->size; i++)
		{
			fwrite(&(p->people[i]), sizeof(struct People), 1, PeopleList);
		}
		fclose(PeopleList);
		PeopleList = NULL;
		SetPosition(65, 2);
		printf("保存成功！！");
		getch();
	}

}

void JudgeSystem(int num)
{
	FILE* pff = fopen("judge.txt", "w");
	if (pff == NULL)
	{
		clean();
		SetPosition(65, 2);
		printf("%s", strerror(errno));
		return;
	}
	else
	{
		fprintf(pff, "%d", num);
		fclose(pff);
		pff = NULL;
	}


}

void JudgeSystem2(int num)
{
	FILE* pff = fopen("judgeMin.txt", "w");
	if (pff == NULL)
	{
		clean();
		SetPosition(65, 2);
		printf("%s", strerror(errno));
		return;
	}
	else
	{
		fprintf(pff, "%d", num);
		fclose(pff);
		pff = NULL;
	}

}


void JudgeSystem3(int num)
{
	FILE* pff = fopen("judgeCount.txt", "w");
	if (pff == NULL)
	{
		clean();
		SetPosition(65, 2);
		printf("%s", strerror(errno));
		return;
	}
	else
	{
		fprintf(pff, "%d", num);
		fclose(pff);
		pff = NULL;
	}

}

int ReadSystem()
{
	int NUM = 0;
	FILE* ppf = fopen("judge.txt", "r");
	if (ppf == NULL)
	{
		clean();
		SetPosition(65, 2);
		printf("%s", strerror(errno));
		return;
	}
	else
	{
		fscanf(ppf, "%d", &NUM);
		fclose(ppf);
		ppf = NULL;
	}
	return NUM;
}

int ReadSystem2()
{
	int NUM = 0;
	FILE* ppf = fopen("judgeMin.txt", "r");
	if (ppf == NULL)
	{
		clean();
		SetPosition(65, 2);
		printf("%s", strerror(errno));
		return;
	}
	else
	{
		fscanf(ppf, "%d", &NUM);
		fclose(ppf);
		ppf = NULL;
	}
	return NUM;
}

int ReadSystem3()
{
	int NUM = 0;
	FILE* ppf = fopen("judgeCount.txt", "r");
	if (ppf == NULL)
	{
		clean();
		SetPosition(65, 2);
		printf("%s", strerror(errno));
		return;
	}
	else
	{
		fscanf(ppf, "%d", &NUM);
		fclose(ppf);
		ppf = NULL;
	}
	return NUM;
}

void GetTime()
{
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	SetPosition(65, 19);
	printf("%d年%d月%d日%d时%d分%d秒", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
}

void Sort(struct PEO* p, int size)
{
	struct People tem;
	int i;
	int j;
	int temp;
	int step = size / 2;
	while (step)
	{
		for (i = step; i < size; i++)
		{
			tem = p->people[i];
			j = i - step;
			while (j >= 0 && p->people[j].age > tem.age)
			{
				p->people[j + step] = p->people[j];
				j -= step;
			}
			p->people[j + step] = tem;
		}
		step = step / 2;
	}
	SetPosition(65, 2);
	printf("排序成功");
	getch();
}
```
