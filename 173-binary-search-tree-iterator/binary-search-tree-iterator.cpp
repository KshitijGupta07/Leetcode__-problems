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
  TreeNode* temp;
    BSTIterator(TreeNode* root) {
        temp=root;
    }
    
    int next() {
        while(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
        temp=st.top();
        int a=temp->val;
        st.pop();
        temp=temp->right;
        return a;
    }
    
    bool hasNext() {
        return !st.empty()||temp!=NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */