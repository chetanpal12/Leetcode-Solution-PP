/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans=true;
    int findBalancedBinaryTree(TreeNode *root){
        if(!root)return 0;
        int leftheight=findBalancedBinaryTree(root->left);
        int rightheight=findBalancedBinaryTree(root->right);
        if(abs(leftheight-rightheight)>1)
            ans=false;
        return 1+max(leftheight,rightheight);
    }
    bool isBalanced(TreeNode* root) {
        findBalancedBinaryTree(root);
        return ans;
    }
};