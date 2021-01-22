

# markdown编辑器学习与语法总结

## 一、标题
# First title(#)
## second (##)
### third (###)
#### fourth(####)
##### fifth title(#####)

---

## 二、字体
**加粗**(** ?**)
*倾斜*(* ? *)
***加粗倾斜*** ( *** ？ ***)
~~删除线~~(~~   ？ ~~)

---

## 三、引用
> C makes it easy to shoot yourself inthe foot; C++ makes it harder, butwhen you do, it blows away your whole leg.  ——Bjarne Stroustrup
---

## 四、 分割线（3+ - or *）

---
***
## 五、图片
![图片使用方法](https://img-blog.csdnimg.cn/20210117134922870.png)
___
![C++之父](https://img-blog.csdnimg.cn/20210117134953404.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTY1OTczOA==,size_16,color_FFFFFF,t_70#pic_center)
***
## 六、超链接
![在这里插入图片描述](https://img-blog.csdnimg.cn/2021011713515754.png)
___
eg.[CSDN](http://www.csdn.net) [百度](http://www.baidu.com) [GitHub](http://www.github.com)
## 七、列表
### 1.无序列表（- 接空格）
- txet1
- txet2
### 2.无序列表（数字后跟点接空格）
1. text1
2. text2
### 3.列表嵌套（上一级与下一级接三个空格）
- text1
   - text2
   1. text1
   
   2. text2
   
      ---
## 八、表格
| 表头1 | 表头2 |
| ----- | ----- |
| 项目1 | 项目2 |
| 项目3 | 项目4 |

| Column1| Column2|Column3|
|:--------:| -------------:|:--------------------------------|
|文本居中| 文本居右 |文本居左|
![表格用法](https://img-blog.csdnimg.cn/20210117141525410.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTY1OTczOA==,size_16,color_FFFFFF,t_70)

---

## 九、代码

```c++
#include<iostream>
using namespace std;
int main()
{
	cout<<"Hello,World!"<<endl;
	return 0;
}
```
![](https://img-blog.csdnimg.cn/20210117142213245.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTY1OTczOA==,size_16,color_FFFFFF,t_70)
---

## 十、流程图

### 流程图方向有下面几个值

TB 从上到下
BT 从下到上
RL 从右到左
LR 从左到右
TD 同TB

eg.从上到下
```mermaid
graph TD
A --> B
```
eg.从左到右
```mermaid
graph LR
C --> D
```
### 基本图形
- id + [文字描述]矩形
- id + (文字描述)圆角矩形
- id + >文字描述]不对称的矩形
- id + {文字描述}菱形
- id + ((文字描述))圆形
```mermaid
graph TB
	id0[矩形]
	id1(圆角矩阵)
	id2>不对称的矩阵]
	id3{菱形}
	id4((圆形))
```
### 节点之间的连接
- A --> B A带箭头指向B
- A --- B A不带箭头指向B
- A -.- B A用虚线指向B
- A -.-> B A用带箭头的虚线指向B
- A ==> B A用加粗的箭头指向B
#### 带有描述的注意字符的左二右三原则
- A -- 描述 --- B A不带箭头指向B并在中间加上文字描述
- A -- 描述 --> B A带箭头指向B并在中间加上文字描述
- A -. 描述 .-> B A用带箭头的虚线指向B并在中间加上文字描述
- A == 描述 ==> B A用加粗的箭头指向B并在中间加上文字描述
```mermaid
graph LR
A-->B---C-.-D-.->E==>F
G--1---H--2-->I-.3.->J==4==>K
```
### 子流程图
```mermaid
graph TB
e-->a
subgraph one
a-->b
end
subgraph two
c-->d
end
subgraph three
e-->f
end
```
### 实战:绘制一个流程图,找出 A、 B、 C 三个数中最大的一个数。
```mermaid
graph TB
start[开始]-->cin(输入三个数A,B,C)-->if1{A>B?}--YES-->if2{A>C?}
if2--YES-->printfA(输出A)-->end1[结束]
if1--NO-->if3{B>C?}--YES-->printfB(输出B)-->end1
if3--NO-->printfC(输出C)-->end1
```

## 参考博客：

## 1. [如何在Markdown中画流程图](https://www.jianshu.com/p/b421cc723da5)

2. [Markdown基本语法](https://www.jianshu.com/p/191d1e21f7ed)



