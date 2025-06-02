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
     int search(vector<int>&inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(element==inorder[i]){
                return i;
            }
        }
        return -1;
     }
     TreeNode* tree(vector<int>&preorder,vector<int>&inorder,int& index,int i,int j){
        cout<<index<<" "<<i<<" "<<j<<endl;
        if(index>=preorder.size()||i>j){
            return NULL;
        }
        
        int pos=search(inorder,preorder[index]);
        TreeNode* temp=new TreeNode(preorder[index++]);
        temp->left=tree(preorder,inorder,index,i,pos-1);
        temp->right=tree(preorder,inorder,index,pos+1,j);
        return temp;
     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        TreeNode* ans=tree(preorder,inorder,index,0,preorder.size()-1);
        return ans;
    }
};