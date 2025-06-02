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
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        TreeNode* temp=root;
        while(temp!=NULL){
           if(temp->left!=NULL){
            TreeNode* temp2=temp->left;
               while(temp2->right!=NULL){
                temp2=temp2->right;
               }
               temp2->right=temp->right;
               temp->right=temp->left;
               temp->left=NULL;

           }
           temp=temp->right;
            
        }
        
        
    }
};