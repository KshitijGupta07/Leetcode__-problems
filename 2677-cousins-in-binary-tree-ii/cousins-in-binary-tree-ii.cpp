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
    TreeNode* replaceValueInTree(TreeNode* root) {
         vector<int>levelsum;
         queue<TreeNode*>q;
         map<TreeNode*,int>m;
         q.push(root);
         q.push(NULL);
         int sum=0;
         int i=0;
         m[root]=root->val;
         while(q.empty()==false){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                if(q.empty()==false){
                    q.push(NULL);
                }
               levelsum.push_back(sum);
               sum=0;
            }
            else{
                sum+=front->val;
                
                if(front->left){
                    q.push(front->left);
                    m[front->left]+=front->left->val;
                    if(front->right){
                        m[front->left]+=front->right->val;
                    }
                }
                if(front->right){
                    q.push(front->right);
                    
                    m[front->right]+=front->right->val;
                    if(front->left){
                        m[front->right]+=front->left->val;
                    }
                }
                
            }
         }
        
         
         q.push(root);
         q.push(NULL);
         
        while(q.empty()==false){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                if(q.empty()==false){
                    q.push(NULL);
                }
                i=i+1;
            }
            else{
                front->val=levelsum[i]-m[front];
                
                if(front->left){
                    
                    
                    q.push(front->left);
                }
                if(front->right){
                    
                    q.push(front->right);
                }
            }
        }
        //  for(auto j:m){
        //     if(j.first){
        //         cout<<j.first->val<<" ";
        //     }
        //     if(j.second){
        //         cout<<j.second->val<<" ";
        //     }
        //     cout<<endl;
        //  }

         
         return root;

    
    }
};