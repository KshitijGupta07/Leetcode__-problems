class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        vector<int>curr(matrix[0].size());
        vector<int>prev(matrix[0].size());
             curr=matrix[0];
             prev=curr;
             int ans=0;
              sort(curr.begin(),curr.end(),greater<int>());
             for(int j=0;j<curr.size();j++){
                ans=max(ans,curr[j]*(j+1));
             }
        for(int i=1;i<matrix.size();i++){
             for(int j=0;j<matrix[0].size();j++){
                 if(matrix[i][j]!=0){
                    prev[j]+=matrix[i][j];
                 }
                 else{
                    prev[j]=0;
                 }
             }
             curr=prev;
             sort(curr.begin(),curr.end(),greater<int>());
             for(int j=0;j<matrix[0].size();j++){
                  ans=max(ans,curr[j]*(j+1));
             }
        }

        return ans;
    }
};