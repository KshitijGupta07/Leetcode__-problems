class Solution {
public:
   vector<int>solve(string expression,int start,int end,vector<vector<vector<int>>>&dp){
      vector<int>result;
       
        if(dp[start][end].size()!=0){
            return dp[start][end];
        }
        
        if(end==start){
            result.push_back(expression[start]-'0');
            return result;
        }
        if(end-start==1&&isdigit(expression[start])){
            int a=10*(expression[start]-'0');
            int b=(expression[end]-'0');
            result.push_back(a+b);
            return result;
        }
        for(int i=start;i<=end;i++){
              if(isdigit(expression[i])){
                continue;
              }
              vector<int>left=solve(expression,start,i-1,dp);
              vector<int>right=solve(expression,i+1,end,dp);
              for(auto j:left){
                for(auto k:right){
                    int r=0;
                      if(expression[i]=='+'){
                        r=(j+k);
                      }
                      if(expression[i]=='-'){
                        r=(j-k);

                      }
                      if(expression[i]=='*'){
                        r=(j*k);
                      }
                      result.push_back(r);
                }
              }
        }
        return result;
   }
    vector<int> diffWaysToCompute(string expression) {
         vector<vector<vector<int>>>dp(expression.length(),vector<vector<int>>(expression.length()));
         return solve(expression,0,expression.length()-1,dp);
    }
};