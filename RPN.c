/* 
RPN 也成为后缀表达式  计算（1-2）*（4+5）  表示为 1 2 - 4 5 + * 
利用栈 数字1 2 进展 遇到减号则弹出两个元素并把计算结果入栈 
*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
 
#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

typedef double ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE *sizeof(ElemType));
	if(!s->base)
		exit(0);
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s,ElemType e)
{
	//栈满，追加空间
	if(s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType *)realloc(s->base,(s->stackSize + STACKINCREMENT*sizeof(ElemType)));
		if(!s->base)
		{
			exit(0);
		}
		s->top = s->base + s->stackSize;
		s->stackSize = s->stackSize + STACKINCREMENT;
	}
	*(s->top) = e;
	s->top++;
}

void Pop(sqStack *s,ElemType *e)
{
	if(s->top == s->base)
		return;
	*e = *--(s->top);
}

int StackLen(sqStack s)
{
	return (s.top-s.base);
}

int main(void)
{
	sqStack s;
	char c;
	double d,e;
	char str[MAXBUFFER]; 
	int i=0;
	InitStack(&s);
	printf("请按照逆波兰表达式进行输入,数据与运算符之间用空格隔开，以#为结束标志\n");
	scanf("%c",&c);
	
	while(c != '#')
	{
		while( isdigit(c) || c == '.') // 判isdigit断参数是否是数字 或者是或者是小数点 
		{
			str[i++]=c;
			str[i]='\0';
			if(i>=10)
			{
				printf("输入的单个数据过大！");
				return -1;
			}
			scanf("%c",&c);
			if(c==' ')
			{
				d=atof(str);//字符串转化为浮点数
				Push(&s,d);
				i=0;
				break; 
			}
		}
		switch(c)
		{
			case '+':
				Pop(&s,&e);
				Pop(&s,&d);
				Push(&s,d+e);
				break;
			case '-':
				Pop(&s,&e);
				Pop(&s,&d);
				Push(&s,d-e); //后出来的减去先出来的 
				break;
			case '*':
				Pop(&s,&e);
				Pop(&s,&d);
				Push(&s,d*e);
				break;
			case '/':
				Pop(&s,&e);
				Pop(&s,&d);
				if( e != 0)
				{
					Push(&s,d/e);
				}
				else
				{
					printf("除数不能为0");
					return -1; 
				}
				break;
		}
		scanf("%c",&c);
	}
	Pop(&s,&d);
	printf("最终的计算结果为  %lf",d);
}
