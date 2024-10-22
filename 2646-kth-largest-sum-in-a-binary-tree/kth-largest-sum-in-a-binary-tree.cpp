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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long >p;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        long long sum=0;
        while(q.empty()==false){
            TreeNode* top=q.front();
            q.pop();
            if(top==NULL){
                 if(q.empty()==false){
                    q.push(NULL);
                 }
                    p.push(sum);
                    sum=0;
                
            }
            else{
                sum+=top->val;
                
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
        }
        int count=0;
        if(p.size()<k){
            return -1;
        }
        while(count!=k-1){
            
            p.pop();
            count++;
        }
        return p.top();
    }
};