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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode* temp=root;
        while(st.empty()==false||temp!=NULL){
            while(temp!=NULL){
                st.push(temp);
                temp=temp->left;
            }
            ans.push_back(st.top()->val);
            temp=st.top();
            st.pop();
            temp=temp->right;

        }
        return ans;
    }
};