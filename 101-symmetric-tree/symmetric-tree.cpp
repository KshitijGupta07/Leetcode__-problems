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
            TreeNode* l1=q.front();
            q.pop();
            TreeNode* l2=q.front();
            q.pop();
            if(l1!=NULL&&l2==NULL){
                return false;
            }
            if(l1==NULL&&l2!=NULL){
                return false;
            }
            if(l1==NULL&&l2==NULL){
                continue;
            }
            if(l1->val!=l2->val){
                return false;
            }
            q.push(l1->left);
            q.push(l2->right);
            q.push(l1->right);
            q.push(l2->left);
        }
        return true;
    }
};