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
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(q.empty()==false){
            TreeNode* front=q.front();
            q.pop();
            if(q.empty()==false&&q.front()==NULL){
                ans.push_back(front->val);
            }
            if(front==NULL){
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