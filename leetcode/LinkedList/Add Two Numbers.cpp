//  2. Add Two Numbers
//  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//  https://leetcode.com/problems/add-two-numbers/


//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1||!l2)
            return l1?l1:l2;
        ListNode* p1=l1,*p2=l2;
        ListNode* t;
        int temp = 0;
        while(p1&&p2){
            temp += p1->val+p2->val;
            p1->val = temp%10;
            temp /=10;
            if(!p1->next)
                t = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1){
            while(temp&&p1){
                temp += p1->val;
                p1->val = temp%10;
                temp /=10;
                if(!p1->next)
                    t = p1;
                p1 = p1->next;
            }
        }
        if(p2){
            t->next = p2;
            while(temp&&p2){
                temp += p2->val;
                p2->val = temp%10;
                temp /=10;
                if(!p2->next)
                    t = p2;
                p2 = p2->next;
            }
        }
        if(temp)
            t->next = new ListNode(1);
        return l1;
            
    }
};

//  concise remedy from disscuss
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}