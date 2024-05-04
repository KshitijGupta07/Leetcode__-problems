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


    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp=root;
        if(root==NULL){
            return NULL;
        }
        stack<TreeNode*>st;
        while(temp!=NULL||st.empty()==false){
               while(temp!=NULL){
                st.push(temp);
                if(temp->val==val){
                    return temp;
                }
                temp=temp->left;
               }
               temp=st.top();
               st.pop();
               temp=temp->right;
        }
        return NULL;
    }
};