//  148. Sort List
//  Sort a linked list in O(n log n) time using constant space complexity.
//  https://leetcode.com/problems/sort-list/

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 // a foolish idea from me,beacuse I use O(nlogn) time complexity but in O(n) space complexity
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        vector<ListNode*> list;
        while(head){
            list.push_back(head);
            head = head->next;
        }
        int size = list.size();
        getSort(list,0,size-1);
        for(int i = 0;i<size-1;i++){
            list[i]->next = list[i+1];
        }
        list[size-1]->next = nullptr;
        return list[0];
    }
    void getSort(vector<ListNode*>& a,int l,int r){
        if(l>=r)
            return;
        int mid = partion(a,l,r);
        getSort(a,l,mid-1);
        getSort(a,mid+1,r);
    }
    int partion(vector<ListNode*>& a,int l,int r){
        int stand = a[l]->val;
        int i = l,j=r+1;
        while(i<j){
            while(a[++i]->val<stand){
                if(i == r)
                    break;
            }
            while(a[--j]->val>stand){
                if(j == l)
                    break;
            }
            if(i>=j){
                break;
            }
            swap(a[i],a[j]);
        }
        swap(a[l],a[j]);
        return j;
    }
};