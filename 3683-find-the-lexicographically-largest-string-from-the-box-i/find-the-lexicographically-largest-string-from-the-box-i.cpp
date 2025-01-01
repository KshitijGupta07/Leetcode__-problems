class Solution {
public:
    string answerString(string word, int n) {
        if(n==1){
            return word;
        }
        char ch='a';
        int l=word.length();
        for(auto j:word){
            ch=max(ch,j);
        }
        if(n==word.length()){
            string x="";
            x.push_back(ch);
            return x;
        }
        vector<string>ans;
        for(int i=0;i<word.length();i++){
            if(word[i]==ch){
                string e="";
                for(int j=i;j<min(i+l-n+1,l);j++){
                     e.push_back(word[j]);
                }
                ans.push_back(e);
            }
        }
        sort(ans.begin(),ans.end());
        
        return ans.back();
        
        
    }
};