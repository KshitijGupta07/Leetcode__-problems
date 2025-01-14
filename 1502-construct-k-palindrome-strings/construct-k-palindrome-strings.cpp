class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(n<k){
            return false;
        }
        vector<int>hash(26,0);
        for(auto j:s){
            hash[j-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(hash[i]%2==1){
                count++;
            }
        }
        if(count>k){
            return false;
        }
        return true;
        
    }
};