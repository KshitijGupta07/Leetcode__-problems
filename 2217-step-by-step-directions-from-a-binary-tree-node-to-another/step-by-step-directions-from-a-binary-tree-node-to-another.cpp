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
  
TreeNode* lca(TreeNode* root,int startValue,int destValue){
    if(root==NULL){
        return NULL;
    }
    if(root->val==startValue){
        return root;
    }
    if(root->val==destValue){
        return root;
    }
    TreeNode* left=lca(root->left,startValue,destValue);
     
    TreeNode* right=lca(root->right,startValue,destValue);
    if(left==NULL&&right==NULL){
        return NULL;
    }
    else if(left==NULL&&right!=NULL){
        return right;
    }
    else if(left!=NULL&&right==NULL){
        return left;
    }
    return root;
}
     void parentmap(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode* &root){
            parent[root]=NULL;
            queue<TreeNode*>q;
            q.push(root);
            while(q.empty()==false){
                TreeNode* front=q.front();
                q.pop();
                if(front->left){
                   q.push(front->left);
                   parent[front->left]=front;
                }
                if(front->right){
                    q.push(front->right);
                    parent[front->right]=front;
                }
            }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* r=lca(root,startValue,destValue);
            
        unordered_map<TreeNode*,TreeNode*>parent;
        parentmap(parent,root);
        TreeNode* start=NULL;
        TreeNode* end=NULL;
        for(auto j:parent){
            if(j.first->val==startValue){
                start=j.first;
                break;
            }
        }
        for(auto j:parent){
            if(j.first!=NULL&&j.first->val==destValue){
                end=j.first;
                break;
            }
        }
        queue<TreeNode*>q;
        string ans="";
        cout<<start->val<<endl;
        q.push(start);
        while(q.empty()==false){
            TreeNode* front=q.front();
            q.pop();
            
            cout<<front->val<<" ";
            if(front!=r){
                q.push(parent[front]);
                ans.push_back('U');
            }
            else if(front==r||front==NULL){
                break;
            }
        }
        queue<TreeNode*>p;
        
        p.push(end);
        string x="";
        while(p.empty()==false){
            TreeNode* front=p.front();
            p.pop();
            if(front==NULL||front==r){
                break;
            }
            else{
                if(parent[front]->left==front){
                    p.push(parent[front]);
                    x.push_back('L');
                }
                if(parent[front]->right==front){
                    p.push(parent[front]);
                    x.push_back('R');
                }
            }
        }
             
             
        
      reverse(x.begin(),x.end());
        return ans+x;
    }
};