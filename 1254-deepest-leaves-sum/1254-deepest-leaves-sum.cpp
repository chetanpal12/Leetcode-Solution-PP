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
    int sum=0;
    int getDepth(TreeNode* root){
        if(!root)return 0;
        return 1+max(getDepth(root->left),getDepth(root->right));
    }
    void findDeepSum(TreeNode* root,int depth,int level){
        if(!root)return;
        if(!root->left&&!root->right&&level==depth)sum+=root->val;
        findDeepSum(root->left,depth,level+1);
        findDeepSum(root->right,depth,level+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
        return 0;
        int depth=getDepth(root);
        findDeepSum(root,depth,1);
        return sum;
    }
};