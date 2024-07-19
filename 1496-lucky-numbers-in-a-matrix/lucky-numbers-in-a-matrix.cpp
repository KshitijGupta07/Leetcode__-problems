class Solution {
public:
    // int findmin(vector<int>&v){
    //     int mini=INT_MAX;
    //     int miniindex=0;
    //     for(int i=0;i<v.size();i++){
    //        if(mini>v[i]){
    //         mini=v[i];
    //         miniindex=i;
    //        }
    //     }
    //     return mini;
    // }
    
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
            int mini=INT_MAX;
            for(int k=0;k<matrix[maxindex].size();k++){
                mini=min(mini,matrix[maxindex][k]);
            }
                if(maxi==mini){
                
                        ans.push_back(maxi);
                    
                
            
            }
            

         }
         
         return ans;
    }
};