/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> asb;
        int res=0;
        for(auto i:A){
            for(auto j:B){
                if(asb.count(i+j)) asb[i+j]++;
                else asb.insert(pair<int,int>(i+j,1));
            }
        }
        for(auto i:C){
            for(auto j:D){
                if(asb.count(-(i+j))) res+=asb[-(i+j)];
            }
        }
        return res;
    }
};
// @lc code=end

