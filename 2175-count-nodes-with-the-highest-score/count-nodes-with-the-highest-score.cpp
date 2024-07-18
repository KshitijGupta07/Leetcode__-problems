class Solution {
public:
     void count(TreeNode* root,unordered_map<TreeNode*,long long>&m){
        if(root==NULL){
            m[root]=0;
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            m[root]=1;
            return;
        }
        count(root->left,m);
        m[root]+=m[root->left];
        count(root->right,m);
        m[root]+=m[root->right]+1;
     }

    int countHighestScoreNodes(vector<int>& parents) {
         int n=parents.size();
         vector<TreeNode*>ans;
         vector<bool>v(n,false);
            unordered_map<TreeNode*,long long>m;
         for(long long  i=0;i<n;i++){
            ans.push_back(new TreeNode(i));
         }
         
         for(int i=0;i<parents.size();i++){
            if(parents[i]!=-1){
                if(v[parents[i]]==false){
                ans[parents[i]]->left=ans[i];
                  v[parents[i]]=true;
                }
                else{
                    ans[parents[i]]->right=ans[i];
                    v[parents[i]]=false;
                }
            }
         }
        TreeNode* root=NULL;
        
        for(int i=0;i<n;i++){
            if(parents[i]==-1){
                root=ans[i];
                break;
            }
        }
        count(root,m);
        // for(auto j:m){
        //     if(j.first!=NULL)
        //     cout<<j.first->val<<" "<<j.second<<endl;
        // }
      map<long long ,long long >frequency;
      for(int i=0;i<ans.size();i++){
         if(ans[i]->left==NULL&&ans[i]->right==NULL){
            frequency[m[root]-1]++;
         }

         else{
            long long element=1;
            if(ans[i]->left!=NULL){
                element*=m[ans[i]->left];
            }
            if(ans[i]->right!=NULL){
                element*=m[ans[i]->right];
            }
            if(parents[i]!=-1){
                element*=m[root]-m[ans[i]];
            }
            frequency[element]++;
         }
      }
      long long  maxi=INT_MIN;
      for(auto j:frequency){
        maxi=max(maxi,j.first);
      }
        return frequency[maxi];
        
    }
};