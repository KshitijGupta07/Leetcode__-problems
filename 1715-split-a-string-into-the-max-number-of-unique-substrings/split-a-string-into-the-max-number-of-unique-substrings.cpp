class Solution {
public:
   int solve(string s,int index,map<string,bool>&present){
    if(index>=s.length()){
        return 0;
    }
    int ans=0;
            for(int i=index;i<s.length();i++){
                if(present[s.substr(index,i-index+1)]==false){
                    present[s.substr(index,i-index+1)]=true;
                    ans=max(ans,1+solve(s,i+1,present));
                    present[s.substr(index,i-index+1)]=false;
                }
            }
            return ans;

   }
    int maxUniqueSplit(string s) {
        map<string,bool>present;
        int ans=solve(s,0,present);
        return ans;
    }
};