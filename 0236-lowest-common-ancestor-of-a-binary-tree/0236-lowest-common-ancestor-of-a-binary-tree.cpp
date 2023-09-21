/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findAllAncestor(TreeNode* root, TreeNode* p, TreeNode* q,vector<TreeNode*>&ancestor_p,vector<TreeNode*>&ancestor_q,vector<TreeNode*>&tmp){
        if(!root)return;
        tmp.push_back(root);
        if(root->val==p->val){
            for(int i=0;i<tmp.size();i++)
                ancestor_p.push_back(tmp[i]);
        }
        if(root->val==q->val){
            for(int i=0;i<tmp.size();i++)
                ancestor_q.push_back(tmp[i]);
        }
        findAllAncestor(root->left,p,q,ancestor_p,ancestor_q,tmp);
        findAllAncestor(root->right,p,q,ancestor_p,ancestor_q,tmp);
        tmp.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ancestor_p,ancestor_q,tmp;
        findAllAncestor(root,p,q,ancestor_p,ancestor_q,tmp);
        int i=0;
        while(i<ancestor_p.size()&&i<ancestor_q.size()){
            if(ancestor_p[i]->val!=ancestor_q[i]->val)
            break;
            i++;
        }
        return ancestor_p[i-1];
    }
};