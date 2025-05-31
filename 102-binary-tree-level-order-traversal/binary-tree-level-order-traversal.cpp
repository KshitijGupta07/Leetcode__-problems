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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        if(root->left==NULL&&root->right==NULL){
            return {{root->val}};
        }
        vector<vector<int>>ans;
        vector<int>node;
        node.push_back(root->val);
        ans.push_back(node);
        node.clear();
        TreeNode* temp=root;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(q.empty()==false){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                if(q.empty()==false){
                    q.push(NULL);
                    ans.push_back(node);
                    node.clear();
                }
            }
            else{
                if(front->left){
                    node.push_back(front->left->val);
                    q.push(front->left);
                    
                }
                if(front->right){
                    node.push_back(front->right->val);
                    q.push(front->right);
                }
            }
            
        }
        return ans;

    }
};