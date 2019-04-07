//  86. Partition List
//  Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//  You should preserve the original relative order of the nodes in each of the two partitions.
//  https://leetcode.com/problems/partition-list/

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
//it is a terrible solution, I believe you can get a better one;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
            return head;
        ListNode* temp = head;
        ListNode* less = new ListNode(0);
        ListNode* dummy = less;
        bool flag = false;
        if(temp->val<x){
            flag = true;
        }
        while(temp&&temp->next){
            ListNode* kp = temp;
            if(kp->next->val < x){
                while(kp->next&&kp->next->val < x)
                    kp = kp->next;
                less->next = temp->next;
                temp->next = kp->next;
                less = kp;
            }
            temp = temp->next;
        }
        temp = head;
        if(flag){
            less->next = temp->next;
            temp->next = dummy->next;
            return temp;
        }else{
            less->next = temp;
            return dummy->next;
        }
    }
};
/* It is a good solution to this question. brife and smart
class Solution {
public:
ListNode *partition(ListNode *head, int x) {
    ListNode node1(0), node2(0);
    ListNode *p1 = &node1, *p2 = &node2;
    while (head) {
        if (head->val < x)
            p1 = p1->next = head;
        else
            p2 = p2->next = head;
        head = head->next;
    }
    p2->next = NULL;
    p1->next = node2.next;
    return node1.next;
}
};
*/