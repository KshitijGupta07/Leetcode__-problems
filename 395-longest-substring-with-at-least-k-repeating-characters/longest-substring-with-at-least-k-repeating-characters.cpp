class Solution {
public:
   int solve(string s,int k,int start,int end){
    if(start>=end){
        return 0;
    }
    map<char,int>m;
    for(int i=start;i<=end;i++){
        m[s[i]]++;
    }
    int mid=0;
    bool si=false;

    for(int i=start;i<=end;i++){
        if(m[s[i]]<k){
            si=true;
            mid=i;
            break;
        }
    }
    if(si==false){
        return end-start+1;
    }
    return max(solve(s,k,start,mid-1),solve(s,k,mid+1,end));

    

   }
    int longestSubstring(string s, int k) {
        map<char,int>m;

        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        bool si=false;
        
        for(int i=0;i<s.length();i++){
            if(m[s[i]]<k){
                
                si=true;
                break;
            }
        }
       if(si==false||k==1){
          return s.length();
       }
       int ans=solve(s,k,0,s.length()-1);
       return ans;

    }
};