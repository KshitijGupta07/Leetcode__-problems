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
    void solve(TreeNode* root,int targetSum,vector<vector<int>>&ans,vector<int>temp){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            if(targetSum==root->val){
                temp.push_back(root->val);
                ans.push_back(temp);
            }
            else{
            
                return ;
            }
                
            
        }
        temp.push_back(root->val);
        targetSum-=root->val;
        solve(root->left,targetSum,ans,temp);
        
        solve(root->right,targetSum,ans,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(root,targetSum,ans,temp);
        return ans;
    }
};