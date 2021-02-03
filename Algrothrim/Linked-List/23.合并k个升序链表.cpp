/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> vec;
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        for(int i=0;i<lists.size();i+=2){
            auto l1=lists[i];
            ListNode *l2=nullptr;
            if(i+1<lists.size()) l2=lists[i+1];
            vec.push_back(work(l1,l2));
        }
        lists.clear();
        return mergeKLists(vec);
    }
    ListNode* work(ListNode *l1,ListNode *l2){
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        if(l1->val<l2->val){
            l1->next=work(l1->next,l2);
            return l1;
        }
        else{
            l2->next=work(l1,l2->next);
            return l2;
        }
        return nullptr;   
    }
};
// @lc code=end

