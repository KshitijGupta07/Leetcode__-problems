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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>ans;
        ans.push_back(root->val);
        while(q.empty()==false){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                if(q.back()){
                ans.push_back(q.back()->val);
                }
                if(q.empty()==false){
                    q.push(NULL);
                }
            }
            else{
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        return ans;
    }
};