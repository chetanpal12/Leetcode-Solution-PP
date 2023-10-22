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
   
    void FindGoodNodes(TreeNode* root,int maxinodes,int &ans){
        if(!root)return;
        if(root->val>=maxinodes){
            ans++;
            maxinodes=max(maxinodes,root->val);
        }
        FindGoodNodes(root->left,maxinodes,ans);
        FindGoodNodes(root->right,maxinodes,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        FindGoodNodes(root,root->val,ans);
        return ans;
    }
};