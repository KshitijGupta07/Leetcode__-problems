class Solution {
public:
    int romanToInt(string s) {

        vector<int>ans;
        int value=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='X'){
                ans.push_back(10);
            }
            if(s[i]=='V'){
                ans.push_back(5);
            }
            if(s[i]=='C'){
                ans.push_back(100);
            }
            if(s[i]=='D'){
                ans.push_back(500);
            }
            if(s[i]=='I'){
                ans.push_back(1);
            }
            if(s[i]=='M'){
                ans.push_back(1000);
            }
            if(s[i]=='L'){
                ans.push_back(50);
            }
            

        }
         for(int i=0;i<ans.size();i++){
             cout<<ans[i]<<" ";
         }
         if(ans.size()==1){
             return ans[0];
         }
         for(int i=0;i<ans.size()-1;){
             if(ans[i]>=ans[i+1]){
                 value=value+ans[i];
                 i++;
             }
             else{
                 value=value+ans[i+1]-ans[i];
                 i+=2;
             }
         }
         if(ans[ans.size()-2]>=ans[ans.size()-1]){
             return value+ans[ans.size()-1];
         }
         return value;
    }
};