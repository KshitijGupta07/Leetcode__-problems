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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        if(root->left==NULL&&root->right==NULL){
            return {{root->val}};
        }
        vector<vector<int>>ans;
        ans.push_back({{root->val}});
        vector<int>node;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        bool flag=false;
        while(q.empty()==false){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                if(q.empty()==false){
                    q.push(NULL);
                    if(flag==false){
                    reverse(node.begin(),node.end());
                    flag=true;
                    }
                    else{
                        flag=false;
                    }
                    ans.push_back(node);
                    node.clear();
                }
            }
            
                else{
                    if(front->left){
                        q.push(front->left);
                        node.push_back(front->left->val);
                    }
                    if(front->right){
                        q.push(front->right);
                        node.push_back(front->right->val);
                    }

                }
                
            }
        
        return ans;
    }
};