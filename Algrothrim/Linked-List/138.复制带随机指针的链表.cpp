/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *,Node *> tmp;
        Node *root=new Node(0);
        Node *rt=root;
        auto h=head;
        tmp[nullptr]=nullptr;
        while(h!=nullptr){
            rt->next=new Node(h->val);
            rt=rt->next;
            tmp[h]=rt;
            h=h->next;
        }
        h=head;
        rt=tmp[h];
        while(h!=nullptr){
            rt->random=tmp[h->random];
            h=h->next;
            rt=rt->next;
        }
        return root->next;
    }
};
// @lc code=end

