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
    bool search(TreeNode* root,int k){
        if(root==NULL){
            return false;
        }
        while(root!=NULL){
            cout<<root->val<<" "<<k<<endl;
            if(root->val==k){
                return true;
            }
            else if(root->val>k){
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
        return false;

    }
     void traverse(vector<int>&temp,TreeNode*root){
          if(root==NULL){
            return;
          }
          traverse(temp,root->left);
          temp.push_back(root->val);
           traverse(temp,root->right);
     }
    bool findTarget(TreeNode* root, int k) {
        if(root->left==NULL&&root->right==NULL){
            return false;
        }
       vector<int>temp;
       traverse(temp,root);
       for(auto j:temp){
        if(k-j!=j&&search(root,k-j)){
            return true;
        }
       }
       return false;
    }
};