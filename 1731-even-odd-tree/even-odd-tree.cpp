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
    bool isEvenOddTree(TreeNode* root) {
        bool s=true;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(q.empty()==false){
            TreeNode* front=q.front();
            q.pop();
            
            if(front!=NULL){
            if(s==true){
                if(q.front()!=NULL){
                    cout<<front->val<<" "<<q.front()->val<<endl;
                    if(front->val%2==0||front->val>=q.front()->val){
                        return false;
                    }
            
                }
                else{
                    cout<<front->val<<endl;
                    if(front->val%2==0){
                        return false;
                    }
                    
                }

            }
            else{
                  if(q.front()!=NULL){
                    cout<<front->val<<" "<<q.front()->val<<endl;
                    if(front->val%2==1||front->val<=q.front()->val){
                        return false;
                    }
                    
                }
                else{
                    cout<<front->val<<endl;
                    if(front->val%2==1){
                        return false;
                    }
                    
                }
            }
             if(front->left){
                q.push(front->left);
             }
             if(front->right){
                q.push(front->right);
             }
            }
            else{
                if(q.empty()==false){
                s=s^false^true;
                q.push(NULL);
                }
            }
        }
        return true;
    }
};