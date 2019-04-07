//  83.Given a sorted linked list, delete all duplicates such that each element appear only once.
//  https://leetcode.com/problems/remove-duplicates-from-sorted-list/

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next )
            return head;
        ListNode* pNode = head;
        ListNode* pNext = head->next;
        while(pNext){
            if(pNode->val == pNext->val){
                pNext = pNext->next;
                delete pNode->next;
                pNode->next = nullptr;
                pNode->next = pNext;
                continue;
            }
            pNode = pNext;
            pNext = pNext->next;
        }
        return head;
    }
};