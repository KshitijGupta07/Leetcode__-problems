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
   bool search(TreeNode* root,TreeNode* target,int k){
        while(root!=NULL){
            if(root->val==k-target->val){
                if(root==target){
                    return false;
                }
                else{
                return true;
                }

            }
            else if(root->val>k-target->val){
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
        return false;
   }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>st;
        TreeNode* temp=root;
        while(temp!=NULL||st.empty()==false){
               while(temp!=NULL){
                    st.push(temp);
                    temp=temp->left;
               }
               if(search(root,st.top(),k)){
                return true;
               }
               temp=st.top();
               st.pop();
               temp=temp->right;

        }
        return false;
    }
};