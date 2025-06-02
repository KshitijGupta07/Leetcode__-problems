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
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        queue<TreeNode*>q;
        q.push(l);
        q.push(r);
        while(q.empty()==false){
            TreeNode* f1=q.front();
            q.pop();
            TreeNode* f2=q.front();
            q.pop();
            if(f1==NULL&&f2==NULL){
                continue;
            }
            if((f1!=NULL&&f2==NULL)||(f1==NULL&&f2!=NULL)||(f1->val!=f2->val)){
                return false;
            }
            if(f1!=NULL){
            q.push(f1->left);
            }
            if(f2!=NULL){
            q.push(f2->right);
            }
            if(f1!=NULL){
            q.push(f1->right);
            }
            if(f2!=NULL){
                q.push(f2->left);
            }
        }
        return true;
    }
};