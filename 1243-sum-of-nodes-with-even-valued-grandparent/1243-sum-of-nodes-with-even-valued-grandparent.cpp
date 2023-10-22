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
    void findSumOfNodes(TreeNode* root,int &ans){
        if(!root)return;
        if(root->val%2==0){
            if(root->left){
                if(root->left->left){
                    ans+=root->left->left->val;
                }
                if(root->left->right){
                    ans+=root->left->right->val;
                }
            }
            if(root->right){
                if(root->right->right){
                    ans+=root->right->right->val;
                }
                if(root->right->left){
                    ans+=root->right->left->val;
                }
            }
        }
        findSumOfNodes(root->left,ans);
        findSumOfNodes(root->right,ans);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        findSumOfNodes(root,ans);
        return ans;
    }
};