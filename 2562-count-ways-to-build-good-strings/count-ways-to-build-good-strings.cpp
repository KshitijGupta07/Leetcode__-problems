class Solution {
public:
     long long solve(int low,int high,int zero,int one,int c,vector<long long>&dp){
        long long element=pow(10,9)+7;
        if(c==high){
            return 1;
        }
                if(c>high)
{
    return 0;
}  
        if(dp[c]!=-1){
            return dp[c];
        }
        if(c<high&&c>=low){
            dp[c]= 1+solve(low,high,zero,one,c+zero,dp)%element+solve(low,high,zero,one,c+one,dp)%element;
            return dp[c]%element;
        }

        dp[c]= solve(low,high,zero,one,c+zero,dp)%element+solve(low,high,zero,one,c+one,dp)%element;  
        return dp[c]%element;    
        
     }
    int countGoodStrings(int low, int high, int zero, int one) {
        int c=0;
        long long element=pow(10,9)+7;
        vector<long long>dp(100001,-1);
        long long ans=solve(low,high,zero,one,c,dp)%element;
        return ans;
    }
};