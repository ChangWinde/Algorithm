// 143. Reorder List
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You may not modify the values in the list's nodes, only nodes itself may be changed.
// https://leetcode.com/problems/reorder-list/

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return ;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = reverse(slow);
        slow = head;
        ListNode* sec = nullptr;
        ListNode* tem = nullptr;
        while(slow->next != fast && slow != fast){
            sec = slow->next;
            tem = fast->next;
            slow->next = fast;
            fast->next = sec;
            slow = sec;
            fast = tem;
        }
        
    }
    ListNode* reverse(ListNode *head){
        ListNode* sec = head;
        ListNode* pre =nullptr;
        while(head){
            sec = sec->next;
            head->next = pre;
            pre = head;
            head = sec;
        }
        return pre;
    }
};