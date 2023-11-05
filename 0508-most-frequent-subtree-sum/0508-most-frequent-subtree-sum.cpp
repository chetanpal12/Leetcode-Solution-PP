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
        vector<int>ans;
        int cnt=INT_MIN;
        int findSum(TreeNode* root){
        if(!root)return 0;
        if(!root->left&&!root->right){
            map[root->val]++;
            return root->val;
        }
        int leftsum=findSum(root->left);
        int rightsum=findSum(root->right);
        map[root->val+leftsum+rightsum]++;
        return root->val+leftsum+rightsum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        findSum(root);
        
        for(auto i=map.begin();i!=map.end();i++){
            cnt=max(cnt,i->second);
        }
        if(cnt>1){
            for(auto it=map.begin();it!=map.end();it++){
                if(cnt==it->second){
                    ans.push_back(it->first);
                    // return ans; because the no.of counts can be same for different number 
                }
                    
            } 
        }else{
            for(auto it=map.begin();it!=map.end();it++){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};


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
// class Solution {
// public:
//     vector<int>ans;
//     unordered_map<int,int>umap;
//     int count=INT_MIN;
//     int findSum(TreeNode* root){
//         if(!root)
//         return 0;
//         if(!root->left&&!root->right){
//             umap[root->val]++;
//             return root->val;
//         }
//         int lst=findSum(root->left);
//         int rst=findSum(root->right);
//         umap[root->val+lst+rst]++;
//         return root->val+lst+rst;
        
//     }
//     vector<int> findFrequentTreeSum(TreeNode* root) {
//         findSum(root);
//         for(auto it=umap.begin();it!=umap.end();it++){
//             count=max(count,it->second);
//         }
//         if(count>1){
//             for(auto it=umap.begin();it!=umap.end();it++){
//                 if(it->second==count){
//                     ans.push_back(it->first);
//                 }
//             }
//         }else{
//             for(auto it=umap.begin();it!=umap.end();it++){
//                 ans.push_back(it->first);
//             }
//         }
//         return ans;
//     }
// };