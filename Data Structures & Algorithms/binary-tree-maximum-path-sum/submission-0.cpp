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
    int Path(TreeNode* root,int &maxval){
        if(!root){
            return 0;
        }

        int res=root->val;
        int x=Path(root->left,maxval);
        int y=Path(root->right,maxval);

        if(x>0){
            res+=x;
        }
        if(y>0){
            res+=y;
        }

        maxval=max(maxval,res);

        return root->val+max(0,max(x,y)); // Change 1
    }

    int maxPathSum(TreeNode* root) {
        int maxval=INT_MIN;

        Path(root,maxval);

        return maxval; // Change 2
    }
};