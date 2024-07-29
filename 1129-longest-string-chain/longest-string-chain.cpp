class Solution {
public:
  bool check(string& a,string& b){
    
    int x=a.length();
    int y=b.length();

    if(abs(x-y)!=1){
        return false;
    }
    
    int count=0;
    int i=0;
    int j=0;
    while(i<a.length()&&j<b.length()){
        if(a[i]==b[j]){
            i++;
            j++;
        }
        else{
            count++;
            if(count>1){
                return false;
            }
            if(a.length()>b.length()){
                i++;
            }
            else if(b.length()>a.length()){
                j++;
            }
            
        }
    }
      
    
    return true;
  }
   int solve(vector<string>&word,int index,int prev,vector<vector<int>>&dp){
     if(index>=word.size()){
        return 0;
     }
     if(dp[index][prev+1]!=-1){
        return dp[index][prev];
     }
     int include=0;
     if(prev==-1||check(word[index],word[prev])==true){
        
        include=1+solve(word,index+1,index,dp);
        
        
   }
   int exclude=solve(word,index+1,prev,dp);
   
   dp[index][prev+1]=max(include,exclude);
   
     
   return dp[index][prev+1];
   }
    int longestStrChain(vector<string>& words) {
       vector<pair<int,string>>p;
       for(int i=0;i<words.size();i++){
        p.push_back({words[i].length(),words[i]});
       }
       sort(p.begin(),p.end());
       for(int i=0;i<words.size();i++){
        words[i]=p[i].second;
        
       }
       vector<vector<int>>dp(words.size(),vector<int>(words.size()+1,-1));
        
        
        int ans=solve(words,0,-1,dp);
        return ans;
    }
};