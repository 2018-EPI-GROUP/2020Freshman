/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        if(n<2) return n;
        long l=0,r=n,mid;
        while(l<r){
            mid=l+(r-l)/2+1;
            if(mid*(mid+1)/2 > n)
                r=mid-1;
            else 
                l=mid;
        }
        return l;
    }
};
// @lc code=end

