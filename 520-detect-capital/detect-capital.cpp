class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        
        for(int i=0;i<word.length();i++){
            if(word[i]>='A'&&word[i]<='Z'){
               count++;
            }
             
        }
        if(word[0]>='A'&&word[0]<='Z'&&count==1){
            return true;
            cout<<1<<endl;
        }
        if(count==0){
            return true;
            cout<<2<<endl;

        }
        if(count==word.length()){
            return true;
            cout<<1<<endl;
        }
        
        return false;

    }
};