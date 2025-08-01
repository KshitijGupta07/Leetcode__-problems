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
    int widthOfBinaryTree(TreeNode* root) {
         queue<pair<TreeNode*,long long>>q;
         q.push({root,1});
         int ans=0;
         while(q.empty()==false){
             int first=q.front().second;
             int last=q.back().second;
             ans=max(ans,last-first+1);
             int a=q.size();
             for(int i=0;i<a;i++){
                 long long  num=q.front().second-first;
                 TreeNode* front=q.front().first;
                 q.pop();
                 if(front->left){
                    q.push({front->left,2LL*num+1});
                 }
                 if(front->right){
                    q.push({front->right,2LL*num+2});
                 }
                 
             }
         }
         return ans;
    }
};