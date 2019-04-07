// 21.Merge two sorted linked lists and return it as a new list. 
//    The new list should be made by splicing together the nodes of the first two lists.
//  https://leetcode.com/problems/merge-two-sorted-lists/

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* t = new ListNode(0);
        ListNode* t3 = t;
        while(t1&&t2){
            if(t1->val<t2->val){
                t->next = new ListNode(t1->val);
                t1 = t1->next;
                t = t->next;
            }else{
                t->next = new ListNode(t2->val);
                t2 = t2->next;
                t = t->next;
            }
        }
        if(!t1){
            t->next = t2;
        }
        if(!t2){
            t->next = t1;
        }
        return t3->next;
    }
};