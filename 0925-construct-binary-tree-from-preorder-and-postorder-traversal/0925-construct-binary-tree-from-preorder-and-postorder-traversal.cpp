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
    unordered_map<int,int>map;
    TreeNode* build(int i1,int j1,int i2,int j2,vector<int>& preorder, vector<int>& postorder){
        if(i1>j1)return NULL;
        if(i1==j1){
            TreeNode* root=new TreeNode(preorder[i1],NULL,NULL);
            return root;
        }
        TreeNode * root=new TreeNode(preorder[i1],NULL,NULL);
        int i=map[preorder[i1+1]];
        root->left=build(i1+1,i1+i-i2+1,i2,i,preorder,postorder);
        root->right=build(i1+i-i2+2,j1,i+1,j2-1,preorder,postorder);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(postorder.size()==0)return NULL;
        for(int i=0;i<postorder.size();i++){
            map[postorder[i]]=i;
        }
        return build(0,preorder.size()-1,0,postorder.size()-1,preorder,postorder);
    }
};