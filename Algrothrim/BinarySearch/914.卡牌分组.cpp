/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */

// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int m[10000]={0};
        for(auto i:deck){
            m[i]++;
        }
        int g=-1;
        for(auto i:m){
            if(i>0){
                if(g==-1) g=i;
                else g=gcd(g,i);
                if(g<=1) return false;
            }
        }
        return true;
    }
    int gcd(int x,int y){
        return x==0?y:gcd(y%x,x);
    }
};
// @lc code=end

