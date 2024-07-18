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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        sort(to_delete.begin(),to_delete.end());
        
        vector<TreeNode*>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false){
            TreeNode* front=q.front();
            q.pop();
           
            if(front->left!=NULL){

                q.push(front->left);
                if(binary_search(to_delete.begin(),to_delete.end(),front->left->val)==true){
                
                front->left=NULL;
                }
            }
            if(front->right!=NULL){
                q.push(front->right);
               if (binary_search(to_delete.begin(),to_delete.end(),front->right->val)==true){
                
                front->right=NULL;
               }

            }
                 if(binary_search(to_delete.begin(),to_delete.end(),front->val)==true){
                    if(front->left){
                       ans.push_back(front->left);
                    }
                    if(front->right){
                        ans.push_back(front->right);
                    }
                
                
                
            }
        
        }
        if(binary_search(to_delete.begin(),to_delete.end(),root->val)==false){
            ans.push_back(root);
        }
        return ans;
    }
};