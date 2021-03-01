/*#include <stdio.h>//代码块作用域
//作用范围是{} 内部 

int main(void)//函数的形参也是隶属于函数体的作用域的 

{
	int i=100;//i1
	{
		int i=110;//i2
		{
			printf("i=%d\n",i);//这一句是打印外作用域中的i，值为110. 
			int i=120;//i3
			printf("i=%d\n",i);//i3与i4是平行的作用域
			//打印时先打印内部的，由于i3与i4平行，则下一个打印为i4，随后向外延伸 
		}
		{
			int i=130;//i4
			printf("i=%d\n",i);
		}
		printf("i=%d\n",i);
	}
	printf("i=%d\n",i);
	
	return 0;
} */

/*#include <stdio.h>//文件作用域
//任何在代码块之外声明的标识符都具有文件作用域（全局变量） 
//范围是从它们声明位置开始到结尾处 （函数名也具有文件作用域）
void func(void);//先声明就无所谓顺序了 

int main(void)
{
	func();
	extern int count;
	count++;
	printf("In main, count = %d\n",count);
	
	return 0;
} 

int count;

void func(void)
{
	count++;
	printf("In func, count = %d\n",count);
}*/



//定义：当一个变量被定义时，编译器会为变量申请内存空间并填充一些值。定义只能一次 
//声明：当一个变量被声明时，编译器就知道该变量被定义在其他地方，声明可以很多次





