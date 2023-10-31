class Solution {
public:
    int getheight(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(getheight(root->left), getheight(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)return 0;
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        int currentDiameter = 1 + getheight(root->left) + getheight(root->right);

        return max(currentDiameter - 1, max(leftDiameter, rightDiameter));
    }
};