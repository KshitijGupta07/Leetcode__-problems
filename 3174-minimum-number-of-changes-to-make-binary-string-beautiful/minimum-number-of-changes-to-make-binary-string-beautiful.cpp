class Solution {
public:
    int minChanges(string s) {
        int count=1;
        int change=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                count++;
            }
            else{
                if(count&1==1){
                    s[i+1]=s[i];
                    i++;
                    change++;
                }
             count=1;
            }
        }
        
        if(count&1==1&&count>1){
            return change+1;
        }
        return change;
    }
};