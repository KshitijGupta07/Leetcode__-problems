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
    bool solve(TreeNode* root,int targetSum){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
        
            if(targetSum==root->val){
                return true;
            }
            else{
                return false;
            }
        }
        targetSum-=root->val;
        bool l=solve(root->left,targetSum);
        bool r=solve(root->right,targetSum);
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        bool ans=solve(root,targetSum);
        return ans;
        
    }
};