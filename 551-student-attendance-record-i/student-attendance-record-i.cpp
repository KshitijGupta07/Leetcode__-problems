class Solution {
public:
    bool checkRecord(string s) {
        int count=0;
    
        
       for(int i=0;i<s.length()-1;i++){
            if(s[i]=='A'){
                count++;
            }
            
            
       } 
       if(s=="AA"){
           return false;
       }
       if(count<2&&(s.find("LLL")<0||s.find("LLL")>=s.length())){
           return true;
       }
       
    

       
       
       
       return false;
    }
};