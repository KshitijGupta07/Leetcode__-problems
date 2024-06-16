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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
          vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>output;
        while(q.empty()==false){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                if(q.empty()==false){
                
                    q.push(NULL);
                }
                    ans.push_back(output);
                    output.clear();
            }
            else{
                output.push_back(front->val);
               if(front->left!=NULL){
                q.push(front->left);
               }
               if(front->right!=NULL){
                q.push(front->right);
               }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
      
    }
};