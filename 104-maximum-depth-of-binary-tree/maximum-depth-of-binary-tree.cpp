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
     void traverse(TreeNode* root,int count,vector<int>&ans){
        if(root==NULL){
            ans.push_back(count);
            count--;
            return;
        }
        count++;
        traverse(root->left,count,ans);
        
        traverse(root->right,count,ans);
        
     }
    int maxDepth(TreeNode* root) {
        int count=0;
        vector<int>ans;
        traverse(root,count,ans);
        int max=INT_MIN;
        for(int i=0;i<ans.size();i++){
            if(max<=ans[i]){
                max=ans[i];
            }
        }
        return max;
    }
};