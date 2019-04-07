//  94. Binary Tree Inorder Traversal
//  Given a binary tree, return the inorder traversal of its nodes' values.
//  https://leetcode.com/problems/binary-tree-inorder-traversal/

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//  Recursive 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr){
            return res;
        }
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
private:
    vector<int> res;
};

//  iteratively
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> nodeStack;
        auto current = root;
        
        for (;;) {
            if (current) {
                nodeStack.push(current);
                current = current->left;
            } else {
                if (nodeStack.empty()) break;
                auto node = nodeStack.top();
                ret.push_back(node->val);
                nodeStack.pop();
                current = node->right;
            }
        }
        
        return ret;
    }
};