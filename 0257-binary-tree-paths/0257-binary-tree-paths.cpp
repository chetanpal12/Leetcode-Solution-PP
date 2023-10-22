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
    vector<string>ans;
    void findPaths(TreeNode* root,string temp){
        if(!root)return;
        if(!root->left&&!root->right){
            temp+=to_string(root->val);
            ans.push_back(temp);
            return;
        }
        temp+=to_string(root->val);
        temp+="->";
        findPaths(root->left,temp);
        findPaths(root->right,temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)return ans;
        findPaths(root,"");
        return ans;
    }
};