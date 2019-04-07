//  237.Delete Node in a Linked List
//  Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
//  https://leetcode.com/problems/delete-node-in-a-linked-list/

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node||!node->next)
            return;
        ListNode *temp = node->next;
        *node = *(node->next);
        delete temp;
    }
};