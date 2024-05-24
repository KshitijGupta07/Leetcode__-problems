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
    void inorder(TreeNode* root,vector<int>&ans,int &val,int &count,int &maxcount){
        if(root==NULL){
            return;
    }
       inorder(root->left,ans,val,count,maxcount);
        if(val==root->val){
            count++;
        }
        else{
            val=root->val;
            count=1;
        }
        if(count>maxcount){
            maxcount=count;
            ans.clear();
            ans.push_back(root->val);
        }
            
         else if(count==maxcount){
            ans.push_back(root->val);
         }   
      
            
        
       
      
       
       inorder(root->right,ans,val,count,maxcount);
       

    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(root->val);
            return ans;
        }
        
        TreeNode* prev=NULL;
        int val=INT_MIN;
        int count=1;
        int maxcount=1;
        inorder(root,ans,val,count,maxcount);
        return ans;
    }
};