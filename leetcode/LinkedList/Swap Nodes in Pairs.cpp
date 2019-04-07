// 24.Given a linked list, swap every two adjacent nodes and return its head.
//    You may not modify the values in the list's nodes, only nodes itself may be changed.
// https://leetcode.com/problems/swap-nodes-in-pairs/

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* pNode = new ListNode(0);
        pNode->next = head;
        ListNode* pre = pNode;
        ListNode* sec = nullptr;
        while(head && head->next){
            sec = head->next;
            head->next = sec->next;
            sec->next = head;
            pre->next = sec;
            pre = head;
            head = head->next;
        }
        return pNode->next;
    }
};
/* 递归版本的解决方法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* pNode = swapPairs(head->next->next);
        ListNode* sec = head->next;
        head->next = pNode;
        sec->next = head;
        return sec;
    }
};
*/