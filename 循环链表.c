#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct List
{
	int data;
	struct List *next;
};

struct List *creatList(struct List *head)
{
	struct List *temp1,*temp2,*temp3;
	int i;
	
	while(1)
	{
		printf("请输入数据(输入0表示结束)：\n");
		scanf("%d",&i);
		if(i==0)
			return head;
		else
		{
			if(head == NULL) // 这是一个空表 
			{
				temp1 = (struct List *)malloc(sizeof(struct List));
				temp1->data=i;
				head=temp1;
				temp1->next=temp1;
			}
			else
			{
				temp1=(struct List *)malloc(sizeof(struct List));
				temp2=head->next;
				while(temp2->next != head)
				{
					temp2=temp2->next; // 寻找尾节点  使用的是尾插法 
				}
				temp1->data = i;
				temp3 = temp2->next;
				temp2->next = temp1;
				temp1->next = temp3;
			}
		}
	}
}

void printList(struct List *head)
{
	struct List *temp;
	temp = head;
	
	while(temp->next != head)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}

void release(struct List *head)
{
	struct List *temp1,*temp2;
	temp1 = head;
	while(temp1->next != head)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		free(temp2);
	}
	free(temp1);
}

int main(void)
{
	struct List *head=NULL;
	head = creatList(head);
	printList(head);
	release(head);
}
