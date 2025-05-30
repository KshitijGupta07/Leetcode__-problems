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
                TreeNode* t=temp->left;
                while(t->right!=NULL&&t->right!=temp){
                    t=t->right;
                }
                if(t->right==NULL){
                    ans.push_back(temp->val);
                    t->right=temp;
                    temp=temp->left;
                }
                else{
                    t->right=NULL;
                    temp=temp->right;
                }
            }
        }
        return ans;
    }
};