//STL队列
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    queue <int> qu;
    int a;
    scanf("%d",&a);
    qu.push(a); //插入元素 
    if(!qu.empty()) { //判断队列是否为空 
        cout<<qu.size()<<endl; //输出队列中元素个数 
        cout<<qu.front(); //输出队首元素 
        qu.pop(); //弹出队首元素 
    }
    return 0;
}

//手写队列
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct queue {
    int Q[500005],head,tail;
    queue() {
        head=0,tail=0;
    }
    void push(int a) {
        Q[++tail]=a;
        return ;
    }
    void pop() {
        head++;
        return ;
    }
    bool empty() {
        return head>=tail;
    }
    int front() {
        return Q[head+1];
    }
    int size() {
        if(head<=tail) return tail-head; 
    } 
};

int main() {
    queue qu;
    int a;
    scanf("%d",&a);
    qu.push(a); //插入元素 
    if(!qu.empty()) { //判断队列是否为空 
        cout<<qu.size()<<endl; //输出队列中元素个数 
        cout<<qu.front(); //输出队首元素 
        qu.pop(); //弹出队首元素 
    }
    return 0;
}
