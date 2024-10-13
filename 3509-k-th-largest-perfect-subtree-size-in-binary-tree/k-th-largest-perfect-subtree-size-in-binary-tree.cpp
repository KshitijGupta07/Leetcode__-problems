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
map<TreeNode*,int>f;
   bool check(map<TreeNode*,pair<int,int>>&p,TreeNode* root){
      if(root==NULL){
        return true;
      }
      if(root->left==NULL&&root->right!=NULL){
        return false;
      }
      if(root->right==NULL&&root->left!=NULL){
        return false;
      }
       if(p[root->left]!=p[root->right]){
        return false;
      }
      
      bool ans=check(p,root->left)&&check(p,root->right);
      return ans;

   }
    int dfs(map<TreeNode*,pair<int,int>>&p,TreeNode* root){
        if(root==NULL){
            return 0;
         }
         if(p[root->left]!=p[root->right]){
            return 0;
         }
         
        
         p[root]={dfs(p,root->left),dfs(p,root->right)};
            
         return 1+dfs(p,root->left)+dfs(p,root->right);

    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
       map<TreeNode*,pair<int,int>>p;
       int size=1;
       dfs(p,root); 
       priority_queue<int>pq;
       vector<int>sizes;
       
       
       for(auto j:p){
         if(j.first!=NULL&&check(p,j.first)&&j.second.first==j.second.second){
            if(j.first!=NULL){
                cout<<j.first->val<<endl;
            }
            sizes.push_back(j.second.first*2 +1);
         }
         
         
         

       }
       for(int i=0;i<sizes.size();i++){
        cout<<sizes[i]<<" ";
        pq.push(sizes[i]);
       }
       if(sizes.size()<k){
        return -1;
       }
       int count=1;
       while(count<k){
        pq.pop();
        count++;
       }
       
       return pq.top();
    }
};