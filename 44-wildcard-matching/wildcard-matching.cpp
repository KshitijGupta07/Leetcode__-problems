class Solution {
public:
//    bool solve(string& s,string &p,int i,int j,vector<vector<int>>&dp){
//     cout<<i<<" "<<j<<endl;
     
//       if(i>=0&&j<0){
//         return false;
//      }
//      if(i<0&&j<0){
//         return true;
//      }
//       if(i<0&&j>=0){
//            int k=j;
//         while(k>=0){
//              if(p[k]!='*'){
//                 return false;
//              }
//              k--;
//         }
//         return true;
//      }
//      if(dp[i][j]!=-1){
//         return dp[i][j];
//      }
   
    
//        bool ans=false;
//      if(s[i]==p[j]||p[j]=='?'){
//            dp[i][j]= solve(s,p,i-1,j-1,dp);
//      }
//     else if(p[j]=='*'){
//          dp[i][j]=solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp);
//      }
//     else{
//         dp[i][j]=false;
//     }
//     return dp[i][j];

//    }
    bool tab(string s,string p){
          vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,0));
          dp[0][0]=true;
          for(int j=1;j<=p.length();j++){
            bool flag=true;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
          }
          
          
         
          
        
          
          for(int i=1;i<=s.length();i++){
            for(int j=1;j<=p.length();j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
                else{
                    dp[i][j]=false;
                }
            }
          }
          return dp[s.length()][p.length()];
    }
    bool isMatch(string s, string p) {
          if(p.length()==0){
            if(s.length()==0){
                return true;
            }
          }
          if(s.length()==0){
            for(int i=0;i<p.length();i++){
                if(p[i]>='a'&&p[i]<='z'||p[i]=='?'){
                    return false;
                }
            }
            return true;
          }
        int i=s.length()-1;
        // int j=p.length()-1;
        // vector<vector<int>>dp(s.length(),vector<int>(p.length(),-1));
        // bool ans=solve(s,p,i,j,dp);
        bool t=tab(s,p);
    
        return t;
    }
};