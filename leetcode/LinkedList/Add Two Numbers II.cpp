//  445. Add Two Numbers II
//  You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//  Follow up:
//  What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
//  https://leetcode.com/problems/add-two-numbers-ii/

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        ListNode *p1 =l1, *p2=l2;
        while(p1){
            s1.push(p1->val);
            p1 = p1->next;
        }
        while(p2){
            s2.push(p2->val);
            p2 = p2->next;
        }
        p1 = nullptr;
        int add = 0;
        while(!s1.empty()||!s2.empty()||add){
            if(!s1.empty()){
                add += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                add += s2.top();
                s2.pop();
            }
            ListNode* n = new ListNode(add%10);
            n->next = p1;
            add /= 10;
            p1 = n;
        }
        return p1;
    }
};