class Solution {
public:
    pair<int,int> findmin(vector<int>&v){
        int mini=INT_MAX;
        int miniindex=0;
        for(int i=0;i<v.size();i++){
           if(mini>v[i]){
            mini=v[i];
            miniindex=i;
           }
        }
        return {mini,miniindex};
    }
    
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        int j=0;
        int count=0;
         for(int i=0;i<matrix[0].size();i++){
            int maxi=INT_MIN;
            int maxindex=0;
            for( j=0;j<matrix.size();j++){
               if(matrix[j][i]>maxi){
                maxi=matrix[j][i];
                maxindex=j;
               }
            }
            
                if(maxi==findmin(matrix[maxindex]).first){
                    if(matrix[maxindex][i]==maxi){
                        ans.push_back(maxi);
                    }
                
            
            }
            

         }
         
         return ans;
    }
};