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
   bool solve(TreeNode* root1,TreeNode* root2){
      if(root1==NULL&&root2==NULL){
        return true;
      }
      if(root1!=NULL&&root2==NULL){
        return false;
      }
      if(root1==NULL&&root2!=NULL){
        return false;
      }
      int a=-1;
      int b=-1;
      int c=-1;
      int d=-1;
      pair<int,int>first;
      if(root1->left){
         a=root1->left->val;
      }
      if(root1->right){
        b=root1->right->val;
      }
      if(root2->left){
        c=root2->left->val;
      }
      if(root2->right){
        d=root2->right->val;
      }
      
      if((a!=c&&a!=d)||(b!=c&&b!=d)){
         return false;
      }
      bool ans1=false;
      bool ans2=false;
      if(a==c){
        ans1= solve(root1->left,root2->left);

      }
      if(a==d){
        ans1= solve(root1->left,root2->right);
      }
      if(b==c){
            ans2=solve(root1->right,root2->left);
      }
      if(b==d){
        ans2=solve(root1->right,root2->right);
      }
      return ans1&&ans2;

   }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1&&root2&&root1->val!=root2->val){
            return false;
        }
        bool ans=solve(root1,root2);
        return ans;
    }
};