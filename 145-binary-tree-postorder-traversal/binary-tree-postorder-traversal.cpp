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
    vector<int> postorderTraversal(TreeNode* root) {
         stack<TreeNode*>s;
        vector<int>ans;
        TreeNode* temp=root;
        while(s.empty()==false||temp!=NULL){
            while(temp!=NULL){
                 s.push(temp);
                 ans.push_back(temp->val);
                    temp=temp->right;
                   
                
            }
            temp=s.top();
            s.pop();
           
           temp=temp->left;

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};