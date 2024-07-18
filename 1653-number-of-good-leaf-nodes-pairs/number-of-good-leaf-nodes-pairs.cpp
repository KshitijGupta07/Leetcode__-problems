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
        int count;
    vector<int> dfs(TreeNode* root,int distance){
        if(root==NULL){
            return {};
        }
        if(root->left==NULL&&root->right==NULL){
            return {1};
        }
        vector<int>left=dfs(root->left,distance);
        vector<int>right=dfs(root->right,distance);
        for(auto x:left){
            for(auto y:right){
                if(x+y<=distance){
                    count++;
                }
            }
        }
        vector<int>parent;
        for(int i=0;i<left.size();i++){
            if(left[i]+1<=distance){
                parent.push_back(left[i]+1);
            }
           
        }
        for(int i=0;i<right.size();i++){
            if(right[i]+1<=distance){
                parent.push_back(right[i]+1);
            }
        }
        return parent;
    }
    int countPairs(TreeNode* root, int distance) {
        count=0;
        dfs(root,distance);
        return count;
    }
};