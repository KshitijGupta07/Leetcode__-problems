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
   void path(vector<string>&ans,TreeNode* root,string& temp){
     
      if(root->left==NULL&&root->right==NULL){
        temp+=to_string(root->val);
        ans.push_back(temp);
        while(temp.empty()==false&&isdigit(temp.back())){
            temp.pop_back();
        }
        if(root->val<0){
            temp.pop_back();
        }
        
        return;
      }
      
       
        if(root->left!=NULL){
             temp+=to_string(root->val);
        temp.push_back('-');
        temp.push_back('>');
            path(ans,root->left,temp);
            temp.pop_back();
            temp.pop_back();
            while(temp.empty()==false&&isdigit(temp.back())){
                temp.pop_back();
            }
            if(root->val<0){
                temp.pop_back();
            }
        
        }
        if(root->right!=NULL){
             temp+=to_string(root->val);
        temp.push_back('-');
        temp.push_back('>');
            path(ans,root->right,temp);
            temp.pop_back();
            temp.pop_back();
            while(temp.empty()==false&&isdigit(temp.back())){
                temp.pop_back();
            }
            if(root->val<0){
                temp.pop_back();
            }
        }
        
   }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root->left==NULL&&root->right==NULL){
            string temp=to_string(root->val);
            return {temp};
        }
        vector<string>ans;
        string temp="";
        path(ans,root,temp);
        return ans;
    }
};