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
long long  solve(TreeNode* root){
    if(root->left==NULL&&root->right==NULL){
        return 1;
    }
    long long left=INT_MAX;
    long long right=INT_MAX;
    if(root->left!=NULL){
        left=1+solve(root->left);
    }
    if(root->right!=NULL){
        right=1+solve(root->right);
    }
    
    return min(left,right);
}
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        long long  ans=solve(root);
        return ans;
    }
};