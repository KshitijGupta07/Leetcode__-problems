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
   void inorder(vector<int>&temp,TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(temp,root->left);
     temp.push_back(root->val);
     inorder(temp,root->right);
   }
    bool isValidBST(TreeNode* root) {
        vector<int>temp;
        inorder(temp,root);
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i]>=temp[i+1]){
                return false;
            }
        }
        return true;
    }
};