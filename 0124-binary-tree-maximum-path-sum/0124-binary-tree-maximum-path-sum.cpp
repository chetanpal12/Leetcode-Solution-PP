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
    pair<int,int>findMaxSumPath(TreeNode* root){
        if(!root)return {INT_MIN,0};
        pair<int,int>leftsubtree=findMaxSumPath(root->left);
        pair<int,int>rightsubtree=findMaxSumPath(root->right);
        int max_sum_path=max({root->val+max(leftsubtree.second,0)+max(rightsubtree.second,0),leftsubtree.first,rightsubtree.first});
        int max_unique_path_sum=root->val+max({leftsubtree.second,rightsubtree.second,0});
       return {max_sum_path,max_unique_path_sum};
    }

    int maxPathSum(TreeNode* root) {
        return findMaxSumPath(root).first;
    }
};