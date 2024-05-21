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
     int search(vector<int>& inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(element==inorder[i]){
                return i;
            }
        }
        return -1;
     }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int inorderstart,int inorderend){
        if(index>=preorder.size()||inorderstart>inorderend){
            return NULL;
        }
        int element=preorder[index++];
        int pos=search(inorder,element);
        TreeNode* temp=new TreeNode(element);
        temp->left=solve(preorder,inorder,index,inorderstart,pos-1);
        temp->right=solve(preorder,inorder,index,pos+1,inorderend);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        TreeNode* ans=solve(preorder,inorder,index,0,preorder.size()-1);
        return ans;
    }
};