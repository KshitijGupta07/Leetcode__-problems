class Solution {
public:
      bool check(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
        return true;
    }
    return false;
   }
   long long solve(string word,int k){
     long long l=0;
     long long r=0;
     long long ans=0;
     map<char,int>m;
     int c=0;
     while(r<word.length()){
        if(check(word[r])){
            m[word[r]]++;
        }
        else{
            c++;
        }
        while(m.size()>=5&&c>k){
            if(check(word[l])){
                m[word[l]]--;
                if(m[word[l]]==0){
                    m.erase(word[l]);
                }
            }
            else{
                c--;
            }
            l++;
        }
        ans+=r-l+1;
        r++;
     }
     return ans;
   }
    long long countOfSubstrings(string word, int k) {
        return solve(word,k)-solve(word,k-1);
    }
};