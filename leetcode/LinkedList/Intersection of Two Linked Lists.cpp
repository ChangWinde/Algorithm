//  160.Write a program to find the node at which the intersection of two singly linked lists begins.
//  https://leetcode.com/problems/intersection-of-two-linked-lists/

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	 if (!headA || !headB) {
		 return nullptr;
	 }
	 ListNode* t1 = headA;
	 ListNode* t2 = headB;
	 int la = 0;
	 int lb = 0;
	 while (t1) {
		 la++;
		 t1 = t1->next;
	 }
	 while (t2) {
		 lb++;
		 t2 = t2->next;
	 }
	 int mid;
	 if (la >= lb) {
		 mid = la - lb;
		 t1 = headA;
		 t2 = headB;
		 while (mid--)
			 t1 = t1->next;
	 }
	 else if (la < lb) {
		 mid = lb - la;
		 t1 = headA;
		 t2 = headB;
		 while (mid--)
			 t2 = t2->next;
	 }
	 while (t1&&t2) {
		 if (t1 == t2)
			 return t1;
		 t1 = t1->next;
		 t2 = t2->next;
	 }
	 return nullptr;
 }
};
/* java实现版本from一个brilliant的人 
// https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    //boundary check
    if(headA == null || headB == null) return null;
    
    ListNode a = headA;
    ListNode b = headB;
    
    //if a & b have different len, then we will stop the loop after second iteration
    while( a != b){
    	//for the end of first iteration, we just reset the pointer to the head of another linkedlist
        a = a == null? headB : a.next;
        b = b == null? headA : b.next;    
    }
    
    return a;
}
*/
