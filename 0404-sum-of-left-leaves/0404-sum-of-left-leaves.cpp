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
    void findSumLeftLeave(TreeNode* root,bool isLeft,int &ans){
        if(!root)return;
        if(!root->left&&!root->right&&isLeft){
            ans+=root->val;
            return;
        }
        findSumLeftLeave(root->left,true,ans);
        findSumLeftLeave(root->right,false,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        if(!root)return ans;
        findSumLeftLeave(root,false,ans);
        return ans;
    }
};