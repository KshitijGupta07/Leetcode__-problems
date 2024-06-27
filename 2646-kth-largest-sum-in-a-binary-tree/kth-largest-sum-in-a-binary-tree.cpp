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
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        long long  sum=0;

        vector<long long>ans;
        while(q.empty()==false){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                if(q.empty()==false){
                q.push(NULL);
                }
              ans.push_back(sum);
              sum=0;
            }
            else{
                sum+=front->val;
                if(front->left){
                    q.push(front->left);

                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        if(ans.size()<k){
            return -1;
        }
         return ans[ans.size()-k];
        

    }
};