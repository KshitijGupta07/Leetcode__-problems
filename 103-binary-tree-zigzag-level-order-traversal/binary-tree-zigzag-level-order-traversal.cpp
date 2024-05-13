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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        

        while(q.empty()==false){
            int size=q.size();
            stack<int>st;
            vector<int>output;
            TreeNode* temp=q.front();
            for(int i=0;i<size;i++){
            temp=q.front();
            q.pop();
            if(flag==true){
            output.push_back(temp->val);
            }
            else{
                st.push(temp->val);
            }
             if(temp->left!=NULL){
            q.push(temp->left);

        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
            
        }
        
        
        
       
        flag=flag^true^false;
        while(st.empty()==false){
            output.push_back(st.top());
            st.pop();
        }
        ans.push_back(output);
        

          

        }
        return ans;
    }
};