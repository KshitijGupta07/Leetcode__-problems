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
    void solve(TreeNode* root,int& sum,string s){
        if(root==NULL){
            return;
        }
       if(root->left==NULL&&root->right==NULL){
        s.push_back(root->val+'0');
          sum=sum+stoi(s);
          return ;
       }
       s.push_back(root->val+'0');
        solve(root->left,sum,s);
        solve(root->right,sum,s);
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        string s="";
        
        solve(root,sum,s);

        return sum;
    }
};