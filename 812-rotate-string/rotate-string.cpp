class Solution {
public:
void rotate(string &s){
    char last= s[s.length()-1];
       
        for(int i=s.length()-1;i>0;i--){
            s[i]=s[i-1];
            
            
        }
        s[0]=last;
        
}

    bool rotateString(string s, string goal) {
        if(s==goal){
            return true;
        }
       for(int count=1;count<s.length();count++){
           rotate(s);
          if(s==goal){
              return true; 
              break;
          }
       }
    

        
        return false;
    }
};