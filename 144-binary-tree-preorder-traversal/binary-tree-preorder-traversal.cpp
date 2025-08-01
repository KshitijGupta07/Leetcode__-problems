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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* temp=root;
        while(temp!=NULL){
            if(temp->left==NULL){
                ans.push_back(temp->val);
                temp=temp->right;
            }
            else{
                
                TreeNode*curr=temp->left;
                while(curr->right!=NULL&&curr->right!=temp){
                    curr=curr->right;
                }
                if(curr->right==NULL){
                    curr->right=temp;
                    ans.push_back(temp->val);
                    temp=temp->left;
                }
                else{
                    curr->right=NULL;
                    temp=temp->right;
                }
            }
        }
        return ans;
    }
};