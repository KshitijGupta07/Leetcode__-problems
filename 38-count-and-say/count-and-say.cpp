class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        int count=1;
        string ans=countAndSay(n-1);
        string p="";
        if(ans.length()==1){
            p.push_back('1');
            p.push_back('1');
        }
        else{
            for(int i=0;i<ans.length()-1;i++){
                if(ans[i]==ans[i+1]){
                    count++;
                }
                else{
                    p+=(to_string(count));
                    p.push_back(ans[i]);
                    count=1;
                }
            }
            p+=(to_string(count));
            p.push_back(ans[ans.length()-1]);
        }
        cout<<ans<<endl;
        return p;

    }
};