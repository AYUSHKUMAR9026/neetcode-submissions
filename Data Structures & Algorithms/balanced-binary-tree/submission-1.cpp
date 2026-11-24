class Solution {
public:
    int height(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int l = height(root->left);
        int r = height(root->right);

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) {
            return 1;
        }

        int h = abs(height(root->left) - height(root->right));

        if(h > 1) {
            return 0;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }
};