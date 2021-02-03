/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr) return nullptr;
        ListNode *p1=head;
        ListNode *p2=nullptr;
        for(int i=0;i<n;i++){
            p1=p1->next;
        }
        p2=p1;
        p1=head;
        if(p2==nullptr){
            return head->next;
        }
        while(p2->next!=nullptr){
            p1=p1->next;
            p2=p2->next;
        }
        p1->next=p1->next->next;
        return head;
    }
};
// @lc code=end

