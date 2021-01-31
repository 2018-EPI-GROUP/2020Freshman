//STL
#include <queue>
priority_queue <int> big_heap; //大根堆
priority_queue <int,vector<int>,greater<int> > small_heap; //小根堆
heap.top();
heap.push();
heap.pop();
heap.empty();
heap.size();

//手写
struct priority_queue {
    int a[23333],size;
    priority_queue() {
        size=0;
    }
    void push(int x) {
        a[++size]=x;
        int son=size,dad;
        while(son!=1) {
            dad=son>>1;
            if(a[dad]>a[son]) swap(a[dad],a[son]);
            son=dad;
        }
        return ;
    }
    int top() {
        return a[1];
    }
    void pop() {
        a[1]=a[size--];
        int dad=1,son=2;
        while(son<=size) {
            son=dad<<1;
            if(son<size && a[son]>a[son+1]) son++;
            if(a[dad]>a[son]) swap(a[son],a[dad]);
            dad=son;
        }
        return ;
    }
    bool empty() {
        return !size;
    }
}; 
