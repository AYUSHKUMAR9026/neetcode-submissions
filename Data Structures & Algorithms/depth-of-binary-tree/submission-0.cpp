class Solution {
    int depth(TreeNode* root, int h, int &m) {
        if (!root) {
            m = max(m, h);
            return m;
        }

        depth(root->left, h + 1, m);
        depth(root->right, h + 1, m);

        return m;
    }

public:
    int maxDepth(TreeNode* root) {
        int h = 0;
        int m = 0;

        return depth(root, h, m);
    }
};