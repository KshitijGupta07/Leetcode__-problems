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
    int widthOfBinaryTree(TreeNode* root) {
        TreeNode* temp=root;
        deque<pair<TreeNode*,long long >>d;
        d.push_back({temp,1});
        
        long long  m=1;
        while(d.empty()==false){
            int size=d.size();
            long long a=d.front().second;
            long long b=d.back().second;
            m=max(m,b-a+1);
            for(int i=0;i<size;i++){
                pair<TreeNode*,int>front=d.front();
                d.pop_front();
                long long idx=front.second-a;
                if(front.first->left!=NULL){
                    d.push_back({front.first->left,2*idx});
                }
                if(front.first->right!=NULL){
                    d.push_back({front.first->right,2*idx+1});
                }
            }
        }
        return m;

    }
};