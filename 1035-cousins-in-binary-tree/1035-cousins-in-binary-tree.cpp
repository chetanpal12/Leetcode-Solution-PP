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
    TreeNode* nodeAparent=NULL,*nodeBparent=NULL;
    bool ans=false;
    int level1=0,level2=0;
    void findcousin(TreeNode* root,int &a,int &b,int level){
        if(!root)return;
        if(root->left){
            if(root->left->val==a){
                nodeAparent=root;
                level1=level+1;
            }
            if(root->left->val==b){
                nodeBparent=root;
                level2=level+1;
            }
        }
        if(root->right){
            if(root->right->val==a){
                nodeAparent=root;
                level1=level+1;
            }
            if(root->right->val==b){
                nodeBparent=root;
                level2=level+1;
            }
        }
    
        findcousin(root->left,a,b,level+1);
        findcousin(root->right,a,b,level+1);
    }
    bool isCousins(TreeNode* root, int a, int b) {
        findcousin(root,a,b,1);
        if(level1==level2&&nodeAparent!=nodeBparent){
            ans=true;
        }
        return ans;
    }
};