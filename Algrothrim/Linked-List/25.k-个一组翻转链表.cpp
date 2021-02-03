/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto p=head;
        for(int i=0;i<k;i++){
            if(p==nullptr) return head;
            p=p->next;
        }
        return work(head,reverseKGroup(p,k),k);
    }
    ListNode *work(ListNode *h,ListNode *pre,int k){
        auto t=h->next;
        h->next=pre;
        if(k==1) return h;
        return work(t,h,k-1);
    }
};
// @lc code=end

