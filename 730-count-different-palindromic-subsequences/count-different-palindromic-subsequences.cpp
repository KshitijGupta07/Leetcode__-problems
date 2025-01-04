class Solution {
public:
    int solve(int i,int j,string &s,vector<vector<int >>&dp){
        int element=pow(10,9)+7;
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
         int  ans=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
        int l=i+1;
        int r=j-1;
        while(l<=r&&s[l]!=s[i]){
            l++;
        }
        while(l<=r&&s[r]!=s[j]){
            r--;
        }
    
        if(l==r){
             ans+=(2*solve(i+1,j-1,s,dp)+1);
        }
        else if(l<r){
            ans+=(2*solve(i+1,j-1,s,dp)-solve(l+1,r-1,s,dp));
        }
        else{
            ans+=(2*(solve(i+1,j-1,s,dp))+2);
        }
        }
        else{
            ans+=(solve(i,j-1,s,dp)+solve(i+1,j,s,dp)-solve(i+1,j-1,s,dp));
        }
        if(ans<0){
            ans+=element;
        }
        dp[i][j]= ans%element;
        return dp[i][j];

    }
    int countPalindromicSubsequences(string s) {
        
        vector<vector<int >>dp(s.length(),vector<int >(s.length(),-1));
        int  ans=solve(0,s.length()-1,s,dp);
        return ans;
    }
};