class Solution {
public:
     bool check(string s,int index,int count,vector<vector<int>>&dp){
       if(index==s.length()){
        return count==0;
       }
       if(dp[index][count]!=-1){
        return dp[index][count];
       }
     
   bool  isvalid=false;
   if(s[index]=='*'){
    
      isvalid=isvalid||check(s,index+1,count,dp);
      isvalid=isvalid||check(s,index+1,count+1,dp);
      if(count){
        isvalid=isvalid||check(s,index+1,count-1,dp);
      }
   }
   else{
    if(s[index]=='('){
        isvalid=isvalid||check(s,index+1,count+1,dp);
    }
    else{
        if(count){
            
            isvalid=isvalid||check(s,index+1,count-1,dp);
        }
    }
   }
     dp[index][count]=isvalid;
     return dp[index][count];
   
}
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        stack<char>st;
        int count=0;
        int index=0;
        
       return check(s,index,count,dp);
    }
};