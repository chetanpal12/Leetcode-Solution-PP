// class Solution {
// public:
//     int getheight(TreeNode* root) {
//         if (!root)
//             return 0;
//         return 1 + max(getheight(root->left), getheight(root->right));
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         if (!root)return 0;
//         int leftDiameter = diameterOfBinaryTree(root->left);
//         int rightDiameter = diameterOfBinaryTree(root->right);
//         int currentDiameter = 1 + getheight(root->left) + getheight(root->right);

//         return max(currentDiameter - 1, max(leftDiameter, rightDiameter));
//     }
// };



class Solution {
public:
    int getheight(TreeNode* root){
        if(!root)
        return 0;
        return 1 + max(getheight(root->left),getheight(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int height=getheight(root->left)+getheight(root->right);
        int d1=diameterOfBinaryTree(root->left);
        int d2=diameterOfBinaryTree(root->right);
        int ans = max({height,d1,d2});
        return ans;
    }
};