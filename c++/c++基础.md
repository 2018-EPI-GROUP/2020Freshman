
# c++基础
+ 基础代码框架
```
#include<iostream>
using namespace std;

int main()
{

system("pause");
return 0;
}

```
+ 基础输入输出函数
```
cin >>  变量名；       // 基本输入
cout << 变量名 <<endl; // 基本输出
```
# 数据类型
|数据类型|占用空间
---|:--:
short(短整形)|2字节|
int(整形)|4字节
long(长整形)|Windows为4字节，Linux为4字节（32位）、8字节（64位）
long long(长长整形)|8字节
float|4字节
double|8字节
char|1字节

**注：正常情况下，小数只显示6位。**

# 字符串
+ 引入头文件#include<string>
  + 用 string 变量名 = “..”；来定义字符串
# bool类型
  + bool类型只占一个字节
  - true --- 真（本质是1）
  - false --- 假（本质是0）
  
