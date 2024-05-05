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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        stack<TreeNode*>t;
        stack<int>sum;
        sum.push(root->val);
        t.push(root);
        while(t.empty()==false){
            int tem=sum.top();
            TreeNode* temp=t.top();
            sum.pop();
            t.pop();
            if(temp->left==NULL&&temp->right==NULL&&tem==targetSum){
                return true;
            }
             if(temp->left!=NULL){
                 t.push(temp->left);
                 sum.push(tem+temp->left->val);
            }
             if(temp->right!=NULL){
                t.push(temp->right);
                sum.push(tem+temp->right->val);
            }
            cout<<tem<<endl;
        }
        return false;
    }
};