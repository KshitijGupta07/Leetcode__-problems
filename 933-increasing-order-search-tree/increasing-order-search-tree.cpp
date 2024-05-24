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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*>st;
        stack<int>final;
        TreeNode* temp=root;
        while(st.empty()==false||temp!=NULL){
              while(temp!=NULL){
                st.push(temp);
                temp=temp->left;
              }
              temp=st.top();
               final.push(temp->val);
              st.pop();
             
              temp=temp->right;
        }
     temp=NULL;
        TreeNode* ans=NULL;
         while(final.empty()==false){
              
            
                
              if(temp==NULL){
                temp=new TreeNode(final.top());
              }
              else{
                ans=new TreeNode(final.top());
                ans->left=NULL;
                ans->right=temp;
                
                temp=ans;
                
                
              }
              
            final.pop();
              
         }
         if(ans==NULL){
            return temp;
         }
        return ans;
    }
};