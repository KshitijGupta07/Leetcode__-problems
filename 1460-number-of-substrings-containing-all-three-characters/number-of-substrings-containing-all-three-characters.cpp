class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int r=0;
        map<char,int>m;
        int ans=0;
        while(r<s.length()){
              m[s[r]]++;
              
              
                
                  
                  while(m.size()==3){
                    ans=ans+(s.length()-r);
                    m[s[l]]-=1;
                
                    if(m[s[l]]==0){
                        m.erase(s[l]);
                        
                    }
                
                    l++;
                    
                  }
              
              
              r++;
            
        }
    
        
    cout<<l<<endl;
        return ans;
    }
};