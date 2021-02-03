/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        stack<int> ss;
        auto h=head;
        for(int i=1;i<m;i++){
            h=h->next;
        }    
        auto tmp=h;
        for(int i=m;i<=n;i++){
            ss.push(h->val);
            h=h->next;
        }    
        while(!ss.empty()){
            tmp->val=ss.top();
            ss.pop();
            tmp=tmp->next;
        }
        return head;
    }
};
// @lc code=end

