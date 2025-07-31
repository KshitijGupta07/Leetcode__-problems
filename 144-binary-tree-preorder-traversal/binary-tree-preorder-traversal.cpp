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
    // void preorder(TreeNode* root,vector<int>&ans){
    //     if(root==NULL){
    //         return;
    //     }
    //     ans.push_back(root->val);
    //     preorder(root->left,ans);
    //     preorder(root->right,ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
    
        vector<int>ans;
        TreeNode* temp=root;
        while(st.empty()==false||temp!=NULL){
            while(temp!=NULL){
                   ans.push_back(temp->val);
                      
                      st.push(temp);
                      temp=temp->left;
            }
             temp=st.top();
            st.pop();
              temp=temp->right;
        }
        return ans;
    }
};