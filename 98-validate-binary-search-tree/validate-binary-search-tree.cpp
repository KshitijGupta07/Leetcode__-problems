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
   bool solve(TreeNode* root,long long b,long long a){
        if(root==NULL){
            return true;
        }
        if(root->val>b&&root->val<a){
            bool left=solve(root->left,b,root->val);
            bool right=solve(root->right,root->val,a);
            return left&&right;
        }
        return false;
   }
    bool isValidBST(TreeNode* root) {
        long long b=INT_MIN-(long long )1;
        long long a=INT_MAX +(long long )1;
        bool ans=solve(root,b,a);
        return ans;
    }
};