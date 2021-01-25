/*
题目：创建一单链表 利用快慢指针进行寻找中间节点 
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct List *CreatList(struct List *head);
void addList(struct List *head);


int a[20];
int i,j=0;

struct List
{
	int i;
	struct List *next;
};

struct List *CreatList(struct List *head)
{
	struct List *temp1,*temp2;
	temp1=(struct List*)malloc(sizeof(struct List));
	
	if(temp1 == NULL)
	{
		printf("内存分配失败！");
		exit(1);
	}
	addList(temp1);
	if(head != NULL)
	{
		temp2=head;
		head = temp1;
		temp1->next = temp2;
	}
	else
	{
		head = temp1;
		temp1->next = NULL;
	}
	return head;
}

void addList(struct List *head)
{
	head->i=a[j++];
}
struct List *searchMid(struct List *head)
{
	struct List *quick,*slow;
	quick = slow = head;
	while(quick->next!= NULL)
	{
		if(quick->next->next!= NULL)
		{
			quick=quick->next->next;
			slow=slow->next;
		}
		else
		{
			quick=quick->next;
		}
	}
	return slow;
}

void printList(struct List *head)
{
	struct List *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d  ",temp->i);
		temp=temp->next;
	}
}

int main(int argc,char *argv[])
{
	struct List *head=NULL;
	struct List *Mid;
	srand(time(0));
	for(i=0;i<20;i++)
	{
		a[i]=rand()%100;
	}
	for(i=0;i<20;i++)
	{
		head=CreatList(head);	
	}
	printList(head);
	Mid=searchMid(head);
	printf("\n%d",Mid->i);
}
