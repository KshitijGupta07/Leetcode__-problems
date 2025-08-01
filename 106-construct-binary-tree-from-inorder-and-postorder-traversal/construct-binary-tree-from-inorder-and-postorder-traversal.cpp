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
    TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int &index,map<int,int>&m,int i,int j){
        if(index<0||i>j){
            return NULL;
        }
        cout<<index<<endl;
        
        int x=m[postorder[index]];
        TreeNode* root=new TreeNode(postorder[index--]);

        root->right=solve(inorder,postorder,index,m,x+1,j);
        root->left=solve(inorder,postorder,index,m,i,x-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size()-1;
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        
        TreeNode* ans=solve(inorder,postorder,index,m,0,postorder.size()-1);
        return ans;
    }
};