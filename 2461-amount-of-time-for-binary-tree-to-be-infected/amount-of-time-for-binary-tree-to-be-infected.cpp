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
    void traverse(TreeNode* root,TreeNode* prev,map<TreeNode*,TreeNode*>&m,TreeNode* &find,int start,int&count){
        if(root==NULL){
               return;
        }
        m[root]=prev;
        count++;
        if(root->val==start){
            find=root;
        }
        traverse(root->left,root,m,find,start,count);
        traverse(root->right,root,m,find,start,count);
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>parent;
        int count=0;
        TreeNode* find=NULL;
        traverse(root,NULL,parent,find,start,count);
        queue<TreeNode*>q;
        q.push(find);
        map<TreeNode*,bool>visited;
        int timer=0;
         while(q.empty()==false){
            
             int a=q.size();
             for(int i=0;i<a;i++ ){
                 TreeNode* front=q.front();
             visited[front]=true;
             q.pop();
             if(parent[front]&&visited[parent[front]]==false){
                q.push(parent[front]);
             }
             if(front->left&&visited[front->left]==false){
                q.push(front->left);
             }
             if(front->right&&visited[front->right]==false){
                q.push(front->right);
             }
             }
             timer++;

         }
    
        
        return timer -1;
        
    }
};