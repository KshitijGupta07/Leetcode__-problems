class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string ans=countAndSay(n-1);
        cout<<ans<<endl;
        int count=1;
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
        return x;
    }
};