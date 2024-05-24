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
void inorder(TreeNode* root,TreeNode* &prev,int &mini){
    if(root==NULL){
        return;
    }
      
       

    inorder(root->left,prev,mini);
       if(prev!=NULL){
        mini=min(abs(root->val-prev->val),mini);
       }
       prev=root;

     inorder(root->right,prev,mini);

}
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev=NULL;
        int mini=INT_MAX;
        inorder(root,prev,mini);
        return mini;
    }
};