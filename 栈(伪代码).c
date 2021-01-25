//顺序存储结构的栈 
typedef struct
{
	ElemType *base; //指向栈底的指针 
	ElemType *top; //指向栈顶的指针 
	int satckSize; //栈当前可用的最大容量 
} sqStack;

//创建一个栈 
#define STAK_INIT_SIZE 100
initStack(sqStack *s)
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if( !s->base)
		exit(0);
	s->top = s->base;//最开始，栈顶就是栈底
	s->stackSize = STACK_INIT_SIZE; 
}

//入栈操作
#define STACKINCREMENT 10

push(sqStack *s,ElemType e)
{
	//如果栈满，追加空间
	if(s->top - s->base >= s->stackSize)
	{
		//realloc函数 新分配一片空间并将原来的内容拷贝到这片空间中 
		s->base = (ElemType *)realloc(s->base,(s->stackSize +STACKINCREMENT )*sizeof(ElemType));
		if(!s->base)
		{
			exit(0);
		}
		s->top = s->base + s->stackSize;             // 设置栈顶
		s->stackSize = s->stackSize + STACKINCREMENT;// 设置栈的最大容量 
	}
	*(s->top) = e;//压栈 
	s->top++; //栈顶指针后移 
} 

//出栈操作 每弹出一个数据 栈的容量减一 栈顶指针向下移一
Pop(sqStack *s,ElemType *e)
{
	if( s->top == s->base) //栈空
		return;
	*e = *--(s->top); 
}

//栈的清空  只是把栈顶的指针指向栈底

ClearStack(sqStack *s)
{
	s->top = s->base;
}

//栈的销毁	需要把之前的数据进行覆盖 

DestroyStack(sqStack *s)
{
	int i,len;
	len = s->stackSize;
	for(i=0;i<len;i++)
	{
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->stackSize = 0;
}

//计算栈的容量  只要计算 s->top - s->base 就可以知道栈的容量了  相减之后并不是地址之差而是之间间隔几个元素

int StackLen(sqStack s)
{
	return(s.top - s.base);
}
