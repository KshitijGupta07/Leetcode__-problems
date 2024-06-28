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
void solve(TreeNode* root,int targetSum,int mysum,vector<int>output,vector<vector<int>>&ans){
   if(root==NULL){
    return;
   }
   if(root->left==NULL&&root->right==NULL){
    mysum+=root->val;
    output.push_back(root->val);
    if(mysum==targetSum){
        ans.push_back(output);
    }
    return;
   }
   
   output.push_back(root->val);
solve(root->left,targetSum,mysum+root->val,output,ans);
solve(root->right,targetSum,mysum+root->val,output,ans);
}


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>output;
        if(root==NULL){
           return ans;
        }
        solve(root,targetSum,0,output,ans);
        return ans;
    }
};