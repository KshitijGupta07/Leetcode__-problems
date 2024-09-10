class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n!=original.size()){
            return {};
        }
        vector<vector<int>>ans;
        vector<int>output;
        for(int i=1;i<=original.size();i++){
             if(i%n==0){
                  output.push_back(original[i-1]);
                ans.push_back(output);
                output.clear();
              
               
             }
             else{
                 output.push_back(original[i-1]);
             }
        }
        return ans;
    }
};