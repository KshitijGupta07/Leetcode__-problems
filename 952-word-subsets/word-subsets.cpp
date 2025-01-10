class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        map<string,vector<int>>m;
        for(int i=0;i<words1.size();i++){
            vector<int>hash(26,0);
            for(int j=0;j<words1[i].length();j++){
                hash[words1[i][j]-'a']++;
            }
            m[words1[i]]=hash;
            hash.clear(); 
        }
        vector<int>hash(26,0);
        for(int i=0;i<words2.size();i++){
            vector<int>hash2(26,0);
            for(int j=0;j<words2[i].length();j++){
                hash2[words2[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                hash[j]=max(hash[j],hash2[j]);
            }
        }
        for(int i=0;i<words1.size();i++){
            vector<int>v=m[words1[i]];
            bool x=false;
            for(int j=0;j<26;j++){
                if(v[j]<hash[j]){
                   x=true;
                   break; 
                }
            }
            if(x==false){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};