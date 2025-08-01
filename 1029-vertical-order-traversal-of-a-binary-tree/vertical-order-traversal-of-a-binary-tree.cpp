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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        q.push({NULL,{-1,-1}});
        map<pair<int,int>,vector<TreeNode*>>m;
        
        while(q.empty()==false){
            TreeNode* front=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            if(front==NULL){
               if(q.empty()==false){
                  q.push({NULL,{-1,-1}});
               }
            }
            else{
                m[{x,y}].push_back(front);
                if(front->left){
                    q.push({front->left,{x+1,y-1}});
                }
                if(front->right){
                    q.push({front->right,{x+1,y+1}});
                }
            }

        }
        map<int,vector<pair<int,int>>>mp;
        for(auto j:m){
            for(auto k:j.second)
            mp[j.first.second].push_back({j.first.first,k->val});
        }
        
        for(auto j:mp){
            sort(j.second.begin(),j.second.end());
            vector<int>temp;
            for(auto k:j.second){
               temp.push_back(k.second);
            }
            ans.push_back(temp);
        }
         
        return ans;
    }
};