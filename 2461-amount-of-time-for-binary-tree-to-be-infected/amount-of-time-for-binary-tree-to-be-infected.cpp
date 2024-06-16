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
   TreeNode* find(TreeNode* &root,int start){
      queue<TreeNode*>q;
      q.push(root);
      while(q.empty()==false){
        TreeNode* front=q.front();
        q.pop();
        if(front->val==start){
            return front;
        }
        else{
            if(front->left){
                q.push(front->left);
                
            }
            if(front->right){
                q.push(front->right);
            }
        }
      }
      return NULL;
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        parentmap(parent,root);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        TreeNode* starting=find(root,start);
        q.push(starting);
        int ans=0;
        visited[starting]=true;
        while(q.empty()==false){
            int a=q.size();
             bool flag=false;
             for(int i=0;i<a;i++){
                 TreeNode* front=q.front();
           
            q.pop();
            if(front->left!=NULL&&visited[front->left]==false){
               flag=true;
               visited[front->left]=true;
               q.push(front->left);
            }
            if(front->right!=NULL&&visited[front->right]==false){
                flag=true;
                visited[front->right]=true;
                q.push(front->right);
            }
            if(parent[front]!=NULL&&visited[parent[front]]==false){
                flag=true;
                visited[parent[front]]=true;
                q.push(parent[front]);
            }
             
         
             }
                if(flag==true){
                ans++;
            }
        }
        return ans;
    }
};