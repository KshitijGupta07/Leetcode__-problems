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
void inorder(TreeNode* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    inorder(root->right,ans);
    ans.push_back(root->val);
      int element=root->val;
    if(ans.size()>1){
       
      
         
        root->val=root->val+ans[0];
        ans[0]=ans[0]+element;
    }
    inorder(root->left,ans);
}
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return root;
    }
};