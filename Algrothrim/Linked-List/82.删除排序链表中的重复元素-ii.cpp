/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode *root=new ListNode();
        auto rt=root;
        auto p=head;
        while(p!=nullptr){
            if(p->next==nullptr) rt->next=p;
            else if(p->val!=p->next->val) rt->next=p;
            else{
                int t=p->val;
                while(p!=nullptr&&p->val==t){
                    p=p->next;
                }
                continue;
            }
            p=p->next;
            rt=rt->next;
        }
        rt->next=nullptr;
        return root->next;
    }
};
// @lc code=end

