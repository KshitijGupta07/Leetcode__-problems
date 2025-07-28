class Solution {
public:
    bool solve(string s,int i,int j,map<string,bool>&found){
        if(j==s.length()-1){
            return found[s.substr(i,j-i+1)];
        }
        
        
        bool ans=false;
        if(found[s.substr(i,j-i+1)]==true){
            ans=solve(s,i,j+1,found)||solve(s,j+1,j+1,found);

        }
        else{
            ans=solve(s,i,j+1,found);
        }
        return ans;
    }
    bool tab(string s,map<string,bool>&found){
        vector<vector<bool>>dp(s.length()+1,vector<bool>(s.length()+1,false));
        for(int i=0;i<s.length();i++){
            dp[i][s.length()-1]=found[s.substr(i,s.length()-i)];
        }
        for(int i=s.length()-1;i>=0;i--){
        
            for(int j=s.length()-1;j>=i;j--){

                if(found[s.substr(i,j-i+1)]){
                    if(j+1<s.length()){
                dp[i][j]=dp[i][j+1]||dp[j+1][j+1];
                    }
                    else{
                        dp[i][j]=true;
                    }
                }
                else{
                    if(j+1<s.length()){
                        dp[i][j]=dp[i][j+1];
                    }
                }
            
            }
        }
        return dp[0][0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool>found;
        for(auto j:wordDict){
            found[j]=true;
        }
        int i=0;
        int j=0;
        bool ans=tab(s,found);
        return ans;
    }
};