class Solution {
public:

   bool solve(string s,int count,int index,vector<vector<int>>&dp,vector<vector<bool>>&pal){
    if(index>=s.length()){
        return false;
    }
    
    if(count==2){
    
        
        if(pal[index][s.length()-1]){
            return true;
        }
        else{
            return false;
        }
    }
    if(dp[index][count]!=-1){
        return dp[index][count];
    }
    
   
    bool l=false;
     for(int i=index;i<s.length();i++){
        
        if(pal[index][i]){
            
            if(count<2){
            count+=1;
            }
            l|=solve(s,count,i+1,dp,pal);
            if(l==true){
                return true;
            }
            count-=1;
            
        }
     }
     return dp[index][count]=l;  
       
   }
    bool checkPartitioning(string s) {
    vector<vector<bool>>pal(s.length(),vector<bool>(s.length(),false));
    for(int i=s.length()-1;i>=0;i--){
        for(int j=i;j<s.length();j++){
            if(s[i]==s[j]&&(j-i<=2||pal[i+1][j-1]==true)){
                pal[i][j]=true;
            }
        }
    }
    vector<vector<int>>dp(s.length(),vector<int>(3,-1));
        int count=0;
        bool ans=solve(s,count,0,dp,pal);
        return ans;
    }
};