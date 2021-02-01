/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size()-1,mid;
        while(l<r){
            mid=l+(r-l)/2+1;
            if(matrix[mid][0]>target)
                r=mid-1;
            else 
                l=mid;
        }
        vector<int> &vec=matrix[l];
        l=0,r=vec.size()-1,mid=0;
        while(l<r){
            mid=l+(r-l)/2;
            if(vec[mid]<target)
                l=mid+1;
            else
                r=mid;
        }
        return vec[l]==target;
    }
};
// @lc code=end

