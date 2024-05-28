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
    bool isBST(long long  min,long long  max,TreeNode* root){
            if(root==NULL){
                return true;
            }
            if(root->val<max&&root->val>min){
                
                bool left=isBST(min,root->val,root->left);
                bool right=isBST(root->val,max,root->right);
                return left&&right;
            }
             
            
                return false;
            
            
    }
    bool isValidBST(TreeNode* root) {
        long long  max=+100000000000;
        long long  min=-100000000000;
    if(root->left==NULL&&root->right==NULL){
        return true;
    }
      bool s=  isBST(min,max,root);
        return s;
    }
};