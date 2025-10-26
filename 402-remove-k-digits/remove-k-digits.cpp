class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k){
            return "0";
        }
        string ans="";
        for(int i=0;i<num.length();i++){
            if(ans.length()==0){
                ans.push_back(num[i]);
            }
            else{
                if(ans.back()>num[i]){
                    while(ans.length()>0&&k>0&&ans.back()>num[i]){
                    ans.pop_back();
                    
                    k--;
                    }
                
                        ans.push_back(num[i]);
                    
                }
                else{
                    ans.push_back(num[i]);
                }
            }
        }
        while(ans[0]=='0'){
            ans.erase(ans.begin());
        }
        while(ans.length()>0&&k>0){
            ans.pop_back();
            k--;
        }
        if(ans.empty()==true){
            return "0";
        }
        return ans;

    }
};