/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target) return true;
            if(nums[l]==nums[mid]){
                for(int i=l;i<=r;i++){
                    if(nums[i]==target) return true;
                }
                return false;
            }
            else if(nums[l]<nums[mid]){
                if(target>=nums[l]&&target<=nums[mid])
                    r=mid-1;
                else l=mid+1;
            }
            else{
                if(target>=nums[mid+1]&&target<=nums[r])
                    l=mid+1;
                else r=mid-1;
            }
        }
        return false;
    }
};
// @lc code=end

