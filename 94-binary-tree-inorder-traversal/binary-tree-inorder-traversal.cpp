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
// void inorder(TreeNode* root,vector<int>& ans){
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left,ans);
//     ans.push_back(root->val);
//     inorder(root->right,ans);

// }
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int>ans;
           if(root==NULL){
        return ans;
      }
       
    else  if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->val);
        return ans;
      }
      stack<TreeNode*>st;
      TreeNode* temp=root;
       while(temp!=NULL||st.empty()==false){
            while(temp!=NULL){
                st.push(temp);
                temp=temp->left;
            }
            
            temp=st.top();
            ans.push_back(temp->val);
            st.pop();
            temp=temp->right;
            
       }
       return ans;
    }
};