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
TreeNode* solve(vector<int>&inorder,vector<int>& postorder,int &index,int start,int end,map<int,int>&m){
    cout<<index<<" "<<start<<" "<<end<<endl;
    if(index<0||start>end){
        return NULL;
    }
    int element=postorder[index];
    int pos=m[element];
    index--;
    TreeNode* temp=new TreeNode(element);
     temp->right=solve(inorder,postorder,index,pos+1,end,m);
    temp->left=solve(inorder,postorder,index,start,pos-1,m);
    return temp;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int index=inorder.size()-1;
        TreeNode*ans=solve(inorder,postorder,index,0,inorder.size()-1,m);
        return ans;
    }
};