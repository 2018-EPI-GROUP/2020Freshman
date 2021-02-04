/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*
        //哈希表法 O(N) O(N)
        unordered_set<ListNode*> ss;
        auto h=head;
        while(h!=nullptr){
            if(ss.count(h)) return true;
            ss.insert(h);
            h=h->next;
        }
        return false; */
        //快慢指针 龟兔赛跑
        if(head==nullptr||head->next==nullptr) return false;
        auto fast=head->next,slow=head;
        while(fast!=slow){
            if(fast==nullptr||fast->next==nullptr) return false;
            slow=slow->next;
            fast=fast->next->next;
        }
        return true;
    }
};
// @lc code=end

