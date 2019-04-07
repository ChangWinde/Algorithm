// 234.Palindrome Linked List
// Given a singly linked list, determine if it is a palindrome.
// https://leetcode.com/problems/palindrome-linked-list/

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast){
            slow = slow->next;
        }
        fast = reverse(slow);
        //slow = head;
        while(fast){
            if(head->val != fast->val)
                return false;
            head = head->next;
            fast = fast->next;
        }
        return true;
    }
     ListNode* reverse(ListNode* head) {
         ListNode* sec = head;
         ListNode* pre = nullptr;
         while (sec) {
             sec = sec->next;
             head->next = pre;
             pre = head;
             head = sec;
         }
         return pre;
     }
};