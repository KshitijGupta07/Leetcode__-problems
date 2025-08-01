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
   TreeNode* solve(vector<int>&preorder,vector<int>&inorder,map<int,int>&m,int &idx,int i,int j){
      if(i>j||idx>=preorder.size()){
        return NULL;
      }
      
     int x=m[preorder[idx]];
      TreeNode* root=new TreeNode(preorder[idx++]);
      
      root->left=solve(preorder,inorder,m,idx,i,x-1);
      root->right=solve(preorder,inorder,m,idx,x+1,j);
      return root;
   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int idx=0;
        TreeNode* ans=solve(preorder,inorder,m,idx,0,preorder.size()-1);
        return ans;
    }
};