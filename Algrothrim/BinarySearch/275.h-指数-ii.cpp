/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0,r=citations.size()-1,mid,n=citations.size();
        while(l<=r){
            mid=l+(r-l)/2;
            if(n-mid==citations[mid])
                return n-mid;
            else if(citations[mid]<n-mid)
                l=mid+1;
            else
                r=mid-1;
            
        }
        return n-l;
    }
};
// @lc code=end

