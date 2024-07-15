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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    
        map<int,bool>visited;
        map<TreeNode*,TreeNode*>parent;
        map<int,TreeNode*>p;
         TreeNode* temp=NULL;
        for(int i=0;i<descriptions.size();i++){
            if(visited[descriptions[i][0]]==false){
                temp=new TreeNode(descriptions[i][0]);
                parent[temp]=NULL;
                 visited[descriptions[i][0]]=true;
                 p[descriptions[i][0]]=temp;
            }
        }  
            
          for(int i=0;i<descriptions.size();i++){
            if(descriptions[i][2]==1){
                if(p[descriptions[i][1]]==NULL){
                p[descriptions[i][0]]->left=new TreeNode(descriptions[i][1]);
                }
                else{
                    p[descriptions[i][0]]->left=p[descriptions[i][1]];
                }
                parent[p[descriptions[i][0]]->left]=p[descriptions[i][0]];
                
            }
            else{
                   if(p[descriptions[i][1]]==NULL){
                p[descriptions[i][0]]->right=new TreeNode(descriptions[i][1]);
                }
                else{
                    p[descriptions[i][0]]->right=p[descriptions[i][1]];
                }
                parent[p[descriptions[i][0]]->right]=p[descriptions[i][0]];
            }
          }
        for(auto j:parent){
            if(j.second==NULL){
                return j.first;
            }
        }
        return NULL;
        
    }
};