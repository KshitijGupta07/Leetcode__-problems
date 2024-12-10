class Solution {
public:
    int maximumLength(string s) {
        vector<int>hash(26,0);
        map<string,int>count;
        
        for(auto j:s){
            hash[j-'a']++;
        }
        
        bool flag=false;
        for(auto j:hash){
            if(j>2){
               flag=true;
               break;
            }
        }
        if(flag==false){
            return -1;
        }
        int l=0;
        int r=0;
        string a="";
        for(int i=0;i<26;i++){
            hash[i]=0;
        }
        while(r<s.length()){
            if(r+1<s.length()&&s[r]==s[r+1]){
                if(a.empty()==true){
                    a.push_back(s[r]);
                    a.push_back(s[r+1]);
                    count[a]++;
                   
                }
                else{
                    a.push_back(s[r+1]);
                    count[a]++;
                    
                }
                
            }
            else{
             
                if(a.length()>0){
                    int x=a.length();
                
                hash[a[0]-'a']=max(hash[a[0]-'a'],x);
                }
                a="";
                while(l!=r){
                    l++;
                }
            }
            r++;
        }
        
      
        
        int ans=1;
        for(int i=0;i<26;i++){
            for(auto j:count){
                if(j.first[0]-'a'==i&&hash[i]!=j.first.length()&&hash[i]>0){
                       cout<<j.first<<hash[i]<<endl;
                    count[j.first]+=(hash[i]-j.first.length());
                }
    
            }
        }
    
        for(auto j:count){
           
            if(j.second>=3){
                
                int a=j.first.length();
                ans=max(ans,a);
            }
        }
      
    
        
  
    return ans;
    }
};