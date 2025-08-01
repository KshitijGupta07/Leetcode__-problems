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
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        TreeNode* temp=root;
        int l=0;
        int r=0;
        while(temp!=NULL){
              l++;
              temp=temp->left;
        }
        temp=root;
        while(temp!=NULL){
            r++;
            temp=temp->right;
        }
        if(l==r){
            return pow(2,l)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};