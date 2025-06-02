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
TreeNode* solve(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL){
        return NULL;
    }
    if(root==p||root==q){
        return root;
    }
    if(p->val>root->val&&q->val<root->val){
        return root;
    }
    if(p->val<root->val&&q->val>root->val){
        return root;
    }
    if(p->val>root->val&&q->val>root->val){
        return solve(root->right,p,q);
    }
    return solve(root->left,p,q);
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=solve(root,p,q);
        return ans;
    }
};