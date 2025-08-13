class Solution {
public:
   int solve(string& str1,string& str2,int i,int j,vector<vector<int>>&dp){
    if(i==0||j==0){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(str1[i-1]==str2[j-1]){
        ans=1+solve(str1,str2,i-1,j-1,dp);
    }
    ans=max(ans,solve(str1,str2,i-1,j,dp));
    ans=max(ans,solve(str1,str2,i,j-1,dp));
    return dp[i][j]=ans;
    
   }
    string shortestCommonSupersequence(string str1, string str2) {
        int i=str1.length();
        int j=str2.length();
        string temp="";
        vector<vector<int>>dp(str1.length()+1,vector<int>(str2.length()+1,-1));
        int ans =solve(str1,str2,i,j,dp);
        
         while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                temp.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                temp.push_back(str1[i-1]);
                i--;
            }
            else{
                temp.push_back(str2[j-1]);
                j--;
            }
         }
         while(j>0){
            temp.push_back(str2[j-1]);
            j-=1;
         }
         while(i>0){
            temp.push_back(str1[i-1]);
                i-=1;
            }
         reverse(temp.begin(),temp.end());
       return temp;
    }
};