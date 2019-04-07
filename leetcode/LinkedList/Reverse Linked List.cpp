//  206. Reverse Linked List
//  Reverse a singly linked list.
//  https://leetcode.com/problems/reverse-linked-list/


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr||head->next == nullptr)
            return head;
        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* next = curr->next;
        while(next){
            curr->next = pre;
            pre = curr;
            curr = next;
            next = curr->next;
        }
        curr->next = pre;
        return curr;
    }
};