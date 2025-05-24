class Solution {
public:
    string countAndSay(int n) {
        int count=1;
        string ans="1";
        for(int i=1;i<n;i++){
            string x="";
        for(int i=0;i<ans.length()-1;i++){
            if(ans[i]==ans[i+1]){
                count++;
            }
            else{
                x.push_back(count+'0');
                x.push_back(ans[i]);
                count=1;
            }
        }
        x.push_back(count+'0');
        x.push_back(ans.back());
        count=1;
        ans=x;
        }
        
        return ans;
    }
};