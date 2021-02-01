/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<=1) return true;
        int l=0,r=num,mid;
        long pow2;
        while(l<=r){
            mid=l+(r-l)/2;
            pow2=(long)mid*mid;
            if(pow2==num)
                return true;
            else if(pow2<num)
                l=mid+1;
            else
                r=mid-1;
            
        }
        return false;
    }
};
// @lc code=end

