#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=1001;
int Next[maxn];
vector<int> Ans;
inline void Get_Next(string s) {
    int l=s.length(),t;
    Next[0]=-1;
    for(int i=1;i<l;++i) {
        t=Next[i-1];
        while(s[t+1]!=s[i]&&t>=0)
            t=Next[t];
        if(s[t+1]==s[i])
            Next[i]=t+1;
        else
            Next[i]=-1;
    }
}
inline void KMP(string s1,string s2) {
    Get_Next(s2);
    int l1=s1.length();
    int l2=s2.length();
    int i=0,j=0;
    while(j<l1) {
        if(s2[i]==s1[j]) {
            ++i;++j;
            if(i==l2) {
                Ans.push_back(j-l2+1);
                i=Next[i-1]+1;               
            }
        }
        else {
            if(i==0)
                j++;
            else
                i=Next[i-1]+1;
        }
    }
}
int main() {
    string s1,s2;
    int l;
    cin>>s1>>s2;
    l=s2.length();
    KMP(s1,s2);
    for(int i=0;i<Ans.size();++i)
    	printf("%d\n",Ans[i]);
    for(int i=0;i<l;++i)
        printf("%d ",Next[i]+1);
    return 0;
}
