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
void inorder(TreeNode* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    TreeNode* createBST(vector<int>&ans,int start,int end){
       TreeNode* root=NULL;
        if(start>end){
            return root;
        }
       
        int mid=start+(end-start)/2 ;
        
             root=new TreeNode(ans[mid]);
              root->left=  createBST(ans,start,mid-1);
             root->right= createBST(ans,mid+1,end); 

       
    
       
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
       inorder(root,ans); 
       int start=0;
       int end=ans.size()-1;
      root= createBST(ans,start,end);
      return root;
    }
};