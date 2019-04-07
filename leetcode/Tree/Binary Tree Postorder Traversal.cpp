//  145. Binary Tree Postorder Traversal
//  Given a binary tree, return the postorder traversal of its nodes' values.
//  https://leetcode.com/problems/binary-tree-postorder-traversal/

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(!s.empty()|| curr){
            if(curr){
                s.push(curr);
                res.insert(res.begin(),curr->val);
                curr = curr->right;
            }else{
                TreeNode* temp = s.top();
                s.pop();
                curr = temp->left;
            }
        }
        return res;
    }
};