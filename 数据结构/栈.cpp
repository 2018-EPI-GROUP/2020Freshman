//STL
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    stack <int> st;
    int a;
    scanf("%d",&a);
    st.push(a); //插入元素 
    if(!st.empty()) { //判断栈是否为空 
        cout<<st.size()<<endl; //输出栈中元素个数 
        cout<<st.top(); //输出栈顶元素 
        st.pop(); //弹出栈顶元素 
    }
    return 0;
}

//手写
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct stack {
    int a[23333],pos;
    stack() {
        pos=0;
    }
    void push(int x) {
        a[++pos]=x;
    }
    void pop() {
        pos--;
    }
    bool empty() {
        return !pos;
    }
    int top() {
        return a[pos];
    }
    int size() {
        return pos;
    }
};

int main() {
    stack st;
    int a;
    scanf("%d",&a);
    st.push(a); //插入元素 
    if(!st.empty()) { //判断栈是否为空 
        cout<<st.size()<<endl; //输出栈中元素个数 
        cout<<st.top(); //输出栈顶元素 
        st.pop(); //弹出栈顶元素 
    }
    return 0;
}
