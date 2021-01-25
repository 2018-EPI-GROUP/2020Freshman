/*
栈的链式存储结构，通常使用的是栈的顺序存储结构，所以此知识点仅供参考 
栈顶做链表的头部栈顶指针和单链表的指针合二为一   简称为栈链 
*/ 

//结构声明 
typedef struct StackNode
{
	ElemType data;//存放栈的数据 
	struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top; // top指针 
	int count;        // 栈元素计数器 
}

//压栈  元素值为e  新节点为s 
Status Push(LinkStack *s,ElemType e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = s->top;
	s->top = p;
	s-<count++;
	return OK;	
}

//弹栈   p存储要删除的栈顶结点
Status Pop(LinkStack *s,ElemType *e)
{
	LinkStackPtr p;
	if(StackEmpty(*s))
		return ERROR;
	*e = s->top->next;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return OK;
}
