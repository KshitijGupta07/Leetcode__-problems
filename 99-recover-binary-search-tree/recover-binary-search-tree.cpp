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
    void recoverTree(TreeNode* root) {
         stack<TreeNode*>st;
         TreeNode* temp=root;
         vector<int>ans;
         map<int,TreeNode*>m;
         while(temp!=NULL||st.empty()==false){
            while(temp!=NULL){
                   st.push(temp);
                   temp=temp->left;
            }
            temp=st.top();
            ans.push_back(temp->val);
            m[temp->val]=st.top();
            st.pop();
            temp=temp->right;
         }
         int index=-1;
         int index2=-1;
         
        
         for(int i=0;i<ans.size()-1;i++){
              if(ans[i]>ans[i+1]){
                if(index==-1){
                    index=i;
                    index2=i+1;
                }
                else{
                    index2=i+1;
                }
              }
              
         }
         
         if(index==index2)return;
         swap(m[ans[index]]->val,m[ans[index2]]->val);

    }
};