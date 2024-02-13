class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string k=words[i];
            string s=k;
            reverse(s.begin(),s.end());
            if(s==k){
                return k;
            }
        }
        return "";
    }
};