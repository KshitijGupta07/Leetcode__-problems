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
class BSTIterator {
public:
stack<TreeNode*>st;

    BSTIterator(TreeNode* root) {
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        
        int a=st.top()->val;
        TreeNode* top=st.top();
        st.pop();
        TreeNode* t=top->right;

            while(t!=NULL){
                st.push(t);
                t=t->left;
            }
        
         return a;
    }
    
    bool hasNext() {
        return !st.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */