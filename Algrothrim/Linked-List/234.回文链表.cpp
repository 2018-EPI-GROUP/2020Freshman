/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        auto h=head;
        while (h!=nullptr)
        {
            vec.emplace_back(h->val);
            h=h->next;
        }
        int i=0,j=vec.size()-1;
        while(i<j){
            if(vec[i]!=vec[j])
                return false;
            i++;j--;
        }
        return true;
    }    
};
// @lc code=end

