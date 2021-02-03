/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        int c=1;
        auto h=head;
        //ListNode *tail=nullptr;
        while(h->next!=nullptr){
            c++;
            h=h->next;
        }
        h->next=head;
        int n=c-k%c-1;
        h=head;
        for(int i=0;i<n;i++){
            h=h->next;
        }
        auto res=h->next;
        h->next=nullptr;
        return res;
    }
};
// @lc code=end

