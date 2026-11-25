class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }

        if(root->val >= min(p->val,q->val) &&
           root->val <= max(p->val,q->val)){
            return root;
        }
        else if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        else{
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};