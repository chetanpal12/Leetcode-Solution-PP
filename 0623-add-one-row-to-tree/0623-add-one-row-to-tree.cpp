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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    // If depth is 1, create a new root.
    if (depth == 1) {
        TreeNode* newRoot = new TreeNode(val);
        newRoot->left = root;
        return newRoot;
    }
    
    // Perform a level order traversal to reach the target depth.
    queue<TreeNode*> q;
    q.push(root);
    int currentDepth = 1;
    
    while (currentDepth < depth - 1) {
        int levelSize = q.size();
        // for (int i = 0; i < levelSize; i++) {
        while(levelSize--){
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        currentDepth++;
    }
    
    // Add new nodes at the target depth.
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        TreeNode* leftChild = new TreeNode(val);
        TreeNode* rightChild = new TreeNode(val);
        
        leftChild->left = node->left;
        rightChild->right = node->right;
        
        node->left = leftChild;
        node->right = rightChild;
    }
    
    return root;
}

};