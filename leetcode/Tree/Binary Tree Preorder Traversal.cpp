//  144. Binary Tree Preorder Traversal
//  Given a binary tree, return the preorder traversal of its nodes' values.
//  https://leetcode.com/problems/binary-tree-preorder-traversal/

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//  O(n) for time O(n) for space
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr){
            return res;
        }
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(!s.empty() || curr){
            if(curr){
                s.push(curr);
                res.push_back(curr->val);
                curr = curr->left;
            }else{
                TreeNode* temp = s.top();
                s.pop();
                curr = temp->right;
            }
        }
        return res;
    }
};