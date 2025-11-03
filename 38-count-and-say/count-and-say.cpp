class Solution {
public:
    string countAndSay(int n) {
        string temp="1";
        
        for(int i=1;i<n;i++){
            int count=1;
            string x="";
            for(int j=0;j<temp.length()-1;j++){
               if(temp[j]!=temp[j+1]){
                   x=x+to_string(count);
                   x.push_back(temp[j]);
                   count=1;
               }
               else{
               count++;
               }

            }
            x=x+to_string(count);
            x.push_back(temp.back());
            temp=x;
        }
        return temp;
    }
};