//  104. Maximum Depth of Binary Tree
//  Given a binary tree, find its maximum depth.
//  The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//  Note: A leaf is a node with no children.
//  https://leetcode.com/problems/maximum-depth-of-binary-tree/

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root)
            return max(maxDepth(root->right),maxDepth(root->left))+1;
        return 0;
    }
};