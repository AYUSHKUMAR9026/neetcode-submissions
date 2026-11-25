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
   void find(TreeNode* root,int level,vector<int>&ans,int &m){
        if(!root){
            level-=1;
            return ;
        }
        if(level>m){
            ans.push_back(root->val);
            m=level;
        }
        find(root->right,level+1,ans,m);
        find(root->left,level+1,ans,m);

   }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int level=1;
        int m=0;
        find(root,level,ans,m);
        return ans;
        
    }
};
