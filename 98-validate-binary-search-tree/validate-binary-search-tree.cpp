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
   bool solve(TreeNode* root,long long  mini,long long maxi){
    if(root==NULL){
        return true;
    }
      bool left=solve(root->left,mini,root->val);
      bool right=solve(root->right,root->val,maxi);
      return left&&right&&(root->val>mini&&root->val<maxi);
   }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool ans=solve(root,INT_MIN-1LL,INT_MAX+1LL);
        return ans;
    }
};