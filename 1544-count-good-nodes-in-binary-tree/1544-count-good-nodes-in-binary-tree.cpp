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
    int ans=0;
    void findgoodnodes(TreeNode* root,int max_up_till){
        if(!root)return;
        if(root->val>=max_up_till){
            max_up_till=root->val;
            ans++;
        }
        findgoodnodes(root->left,max_up_till);
        findgoodnodes(root->right,max_up_till);
    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        findgoodnodes(root,root->val);
        return ans;
    }
};