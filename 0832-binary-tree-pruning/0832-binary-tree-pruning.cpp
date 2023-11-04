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
    int hasOne(TreeNode* root){
        if(!root)
        return 0;
        if(!root->left&&!root->right){
            if(root->val==0)
            return 0;
            else
            return 1;
        }
        int lst=hasOne(root->left);
        int rst=hasOne(root->right);
        if(lst==0)
            root->left=NULL;
        if(rst==0)
            root->right=NULL;
        return lst+rst+root->val; //(root->val==1?1:0)
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(hasOne(root)==0)
        return NULL;
        return root;
    }
};