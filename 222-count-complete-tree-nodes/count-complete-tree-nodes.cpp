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
        if(root==NULL){
            return 0;
        }

        stack<TreeNode*>st;
        st.push(root);
        int count=1;
        while(st.empty()==false){
            TreeNode* temp=st.top();
            st.pop();
            if(temp->left==NULL&&temp->right==NULL&&st.empty()==true){
                break;
            }
            if(temp->left!=NULL){
                count++;
                st.push(temp->left);
            }
            if(temp->right!=NULL){
                count++;
                st.push(temp->right);
            }
        }
        return count;

    }
};