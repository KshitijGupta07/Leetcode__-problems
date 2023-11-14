class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        if(n==1){
            
            return ans;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(__gcd(j,i)==1||j==1){
                string s="";
                s=s+to_string(j)+"/"+to_string(i);
              ans.push_back(s);
              s="";
            }
              
            }
        }
        return ans;
    }
};