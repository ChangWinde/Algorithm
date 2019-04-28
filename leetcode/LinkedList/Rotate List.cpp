//  61. Rotate List
//  Given a linked list, rotate the list to the right by k places, where k is non-negative.
//  https://leetcode.com/problems/rotate-list/

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr||k==0)
            return head; 
        int count = 0;
        ListNode* res = head;
        ListNode* fast = head;
        while(fast){
            count++;
            fast = fast->next;
        }
        k = k%count;
        if(!k)
            return head;
        fast = head;
        while(k){
            fast = fast->next;
            k--;
        } 
        while(fast->next){
            fast = fast->next;
            res = res->next;
        }
        ListNode* temp = res;
        res = res->next;
        temp->next = nullptr;
        fast->next = head;
        return res;
    }
};