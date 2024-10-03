class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>ans;
        long long  sum=0;
        sum=(sum*10+(word[0]-'0'))%m;
        if(sum==0){
            ans.push_back(1);
        }
        else{
            ans.push_back(0);
        }
        for(int i=1;i<word.length();i++){

          sum=(sum*10+(word[i]-'0'))%m;
            
            if(sum==0){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
              
        }
        return ans;
    }
};