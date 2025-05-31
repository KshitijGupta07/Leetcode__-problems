/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   TreeNode* solve(TreeNode* &root,TreeNode* p,TreeNode* q){
    if(root==NULL){
        return NULL;
    }
       if(root==p||root==q){
        return root;
       }
       TreeNode* l=solve(root->left,p,q);
       TreeNode* r=solve(root->right,p,q);
       if(l!=NULL&&r!=NULL){
        return root;
       }
       if(l==NULL&&r!=NULL){
        return r;
       }
       if(l!=NULL&&r==NULL){
        return l;
       }
       return NULL;
   }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=solve(root,p,q);
        return ans;
    }
};