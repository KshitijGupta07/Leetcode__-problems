/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* temp=root;
        while(temp!=p&&temp!=q){
            cout<<temp->val<<endl;
            if(temp->val==p->val||temp->val==q->val){
            return temp;
        }
          else  if(temp->val>p->val&&temp->val<q->val){
                return temp;
            }
           else if(temp->val<p->val&&temp->val>q->val){
                return temp;
            }
           else if(temp->val>p->val&&temp->val>q->val){
                temp=temp->left;
           }
           else{
            temp=temp->right;
           }
        }
        if(temp==p||temp==q){
            return temp;
        }

        return NULL;
    }
};