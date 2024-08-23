class Solution {
public:
void convert(vector<int>&ans){
    for(int i=ans.size()-1;i>=1;i--){
        if(ans[i]>=10){
            ans[i-1]+=ans[i]/10;
            ans[i]=ans[i]%10;
        }
    }
    if(ans[0]>=10){
        int a=ans[0];
        ans[0]=ans[0]%10;
        while(a>=10){
            a/=10;
            ans.insert(ans.begin(),a);
        }
    }
}
    string multiply(string num1, string num2) {
        int n=num1.length();
        int m=num2.length();
        if(num2=="0"||num1=="0"){
            return "0";
        }
        vector<int>ans(n+m,0);
        if(n>=m){
            for(int i=0;i<m;i++){
                int k=i+1;
                for(int j=0;j<n;j++){
                    ans[k]+=((num1[j]-'0')*(num2[i]-'0'));
                    k++;
                }
                while(k<n){
                    ans[k]+=0;
                    k++;
                }
                convert(ans);
                
            }
        }
        else{
                  for(int i=0;i<n;i++){
                int k=i+1;
                for(int j=0;j<m;j++){
                    ans[k]+=((num2[j]-'0')*(num1[i]-'0'));
                    k++;
                }
                while(k<n){
                    ans[k]+=0;
                    k++;
                }
                convert(ans);
                
            }
        }
        string finalp="";
        for(auto j:ans){
            finalp+=to_string(j);
        }
        if(finalp[0]=='0'){
            finalp.erase(finalp.begin());
        }
        return finalp;
    }
};