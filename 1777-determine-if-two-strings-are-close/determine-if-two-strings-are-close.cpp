class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int a=word1.length();
        int b=word2.length();
        if(a!=b){
            return false;
        }
        if(a==1){
            if(word1[0]==word2[0]){
                return true;
            }
            else{
                return false;
            }
        }
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        if(word1==word2){
            return true;
        }
        int c=1;
        int d=1;
        char e='0';
        char f='0';
        vector<int>x;
        vector<int>y;
        
        for(int i=0;i<word1.size()-1;i++){
           if(word1[i]==word1[i+1]){
               c++;
           } 
           else{
             x.push_back(c);
             e=e^word1[i];
             c=1;  
               
           }
        }
        
           for(int i=0;i<word2.size()-1;i++){
           if(word2[i]==word2[i+1]){
               d++;
           } 
           else{
            y.push_back(d);
            f=f^word2[i];
            d=1;
            
               
           }
        }
        x.push_back(c);
        y.push_back(d);
        e=e^word1[word1.length()-1];
        f=f^word2[word2.length()-1];
        

        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if(x==y&&e==f){
            return true;
        }
        
         
        
        return false;

    }
};