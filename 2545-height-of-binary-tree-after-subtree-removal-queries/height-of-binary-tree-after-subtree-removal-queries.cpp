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
   int height(TreeNode* root,map<TreeNode*,int>&m){
      if(root==NULL){
        return 0;
      }
      if(m.count(root)){
        return m[root];
      }
      int left=height(root->left,m);
      int right=height(root->right,m);
      
      m[root]= max(left,right)+1;
      return max(left,right)+1;

   }
   void dfs(TreeNode* root,map<TreeNode*,int>&m,int maxval,int depth,map<int,int>&result){
    if(root==NULL){
        return;
    }
      result[root->val]=maxval-1;
      dfs(root->left,m,max(maxval,1+depth+height(root->right,m)),depth+1,result);
      dfs(root->right,m,max(maxval,1+depth+height(root->left,m)),depth+1,result);
   }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        map<TreeNode*,int>m;
        map<int,int>result;
        dfs(root,m,0,0,result);
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(result[queries[i]]);
        }

        

        return ans;
    }
};