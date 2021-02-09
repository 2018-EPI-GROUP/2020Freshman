
# C++核心编程
## 1、主要针对C+ +面向对象编程技术
+ 1、内存分区模型
  
  C++程序在执行时，将内存大方向划分为4个区域

  ●代码区:存放函数体的二进制代码工由操作系统进行管理的

  ●全局区:存放全局变量和静态变量以及常量
  
  ●栈区:由编译器自动分配释放存放函数的参数值，局部变量等
  
  ●堆区:由程序员分配和释放若程序员不释放程序结束时由操作系统回收
+ 内存四区意义:

**不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程**

+ 2、程序运行前

在程序编译后，生成了exe可执行程序，未执行该程序前分为两个区域

    代码区:
   
    存放CPU执行的机器指令
    
    代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
    
    代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令

    全局区:

    全局变静态变是存放在此。
    
    全局区还包含了常星区字符串常量和其他常量也存放在此
    
    该区域的数据在程序结束后由操作系统释放

+ 3、总结:

●C++中在程序运行前分为全局区和代码区

●代码区特点是共享和只读

●全局区中存放全局变量、静态变量、常量

●常量区中存放const修饰的全局常量和字符串常量

●局部变量存储在栈区里

**对于区的存放代码运行结果（16进制转int）**
```
局部变量a的地址为: 5961520
局部变量b的地址为: 5961508
全局变量g_a的地址为:10272820
全局变量g_b的地址为:10272824
静态变量s_a的地址为: 10272828
静态变量s_b的地址为: 10272832
字符串常量的地址为: 10263396
全局常量C_g_a的地址为:10264208
全局常量C_g_b的地址为: 10264212
局部常量C_1_a的地址为: 5961496         
局部常量e_1_b的地址为:5961484
```
+ 4、堆区的使用
**堆区是由我们自己开辟内存和取消的，主要会使用new关键字**

**new操作符**

C++中利用new操作符在堆区开辟数据

堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete

语法: new数据美型

利用new创建的数据，会返回该数据对应的类型的指针

  代码演示
  ```
#include<iostream>
using namespace std;
int* fun()
{
	int* m = new int(10);
	return m;
}
int main()
{
	int* p = fun();
	cout << *p << endl;
	system("pause");
	return 0;
} 
  ```
  new 处堆区数据的删除
  使用delete _
  代码演示
```
#include<iostream>
using namespace std;
int* fun()
{
	int* m = new int(10);

	return m;
}
int main()
{
	int* p = fun();
	cout << *p << endl;
	cout << *p << endl;
		delete m;
	cout << *p << endl;
	system("pause");
	return 0;
}
以上这种情况能打印出来2个10
```
用new创建堆区数组
```
#include<iostream>
using namespace std;
int* fun()
{
	int* m = new int[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> m[i];
	}
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
	}
	delete m;
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
	}
	return m;
}
int main()
{
	int* p = fun();
	system("pause");
	return 0;
}
```
+ 5、引用

引用的基本使用

作用：给变量起别名

语法：数据类型 &别名 = 原名

代码演示
```
#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	int& b = a;
	b = 110;
	cout << a;//此时的a就是110
	system("pause");
	return 0;
}
```
**引用做函数参数**
作用：函数参数时，可以利用引用的技术让形参修饰实参。
优点：可以简化指针修饰实参。
```
void myswap(int &a,int &b)
(
int temp = a;
a = b;
b = temp;
}
int main()
{
myswap(a,b);
}
```
引用的辅助操作
```
#include<iostream>
using namespace std;
int& test1()
{
	static int a = 10;//改局部变量为静态变量，存储在全局区
	return a;
}
int main()
{  
	int& ref = test1();
 
	cout << ref << endl;
	test1() = 1000;
	cout << ref << endl;
	//结果:10
	       1000
```

