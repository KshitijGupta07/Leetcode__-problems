class Solution {
public:
    void rev(string &s,int start,int end){
        while(start<=end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int l=0;
        int r=0;
        int n=s.length()-1;
        while(s[n]==' '){
            n--;
        }
        while(s[l]==' '){
            l++;
        }
        r=l;
        while(r<=n){
             if(s[r]==' '){
                
                  if(s[l]==' '){
                  rev(s,l+1,r-1);
                  }
                  else{
                    rev(s,l,r-1);
                  }
                  l=r;
             }
             r++;
             
        }
        if(s[l]==' '){
        l=l+1;
        }
        r=r-1;
        rev(s,l,r);
        string ans="";
        l=0;
        
        while(s[l]==' '){
            l++;
        }
        r=s.length()-1;
        while(s[r]==' '){
            r--;
        }
        
        while(l<=r){
            
            if(l+1<=r&&(s[l]!=' '||s[l+1]!=' ')){
                
                 ans.push_back(s[l]);
                
            }
            l++;
           
            
        }
        ans.push_back(s[r]);
        
        return ans;

    }
};