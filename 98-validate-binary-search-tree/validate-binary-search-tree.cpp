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
   bool solve(TreeNode* root,long long  mini,long long maxi){
    
    if(root==NULL){
        return true;
    }
      if(root->val>mini&&root->val<maxi){
        cout<<root->val<<" "<<mini<<" "<<maxi<<endl;
        long long element=root->val;
        bool left=solve(root->left,mini,min(maxi,element));
        bool right=solve(root->right,max(mini,element),maxi);
        return left&&right;

      }
      return false;
   }
    bool isValidBST(TreeNode* root) {
        long long  mini=INT_MIN-1LL;
        long long  maxi=INT_MAX+1LL;
        bool ans=solve(root,mini,maxi);
        return ans;
    }
};