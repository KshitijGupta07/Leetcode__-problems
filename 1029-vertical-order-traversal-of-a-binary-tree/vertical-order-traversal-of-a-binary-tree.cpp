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
   void dfs(TreeNode* &root,map<pair<int,int>,vector<int>>&m,int num,int level){
       if(root==NULL){
        return;
       }
       m[{level,num}].push_back(root->val);
       level=level+1;
       dfs(root->left,m,num-1,level);
       dfs(root->right,m,num+1,level);
   }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,vector<int>>m;
        int level=0;
        dfs(root,m,0,level);
      
        map<int,vector<int>>mp;
       vector<vector<int>>ans;
       for(auto j:m){
    
        vector<int>temp=j.second;
        sort(temp.begin(),temp.end());
        m[j.first]=temp;
        
       }
       for(auto j:m){
         for(auto k:j.second){
            cout<<k<<" ";
         }
         cout<<endl;
       }
       for(auto j:m){
          
        for(auto k:j.second){
            
             mp[j.first.second].push_back(k);
        }
        cout<<endl;
       }
       for(auto j:mp){
        
         ans.push_back(j.second);
        
       }
       return ans;
    }
};