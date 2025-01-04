class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>>hash(26);
        vector<vector<int>>hash2(26);
        map<string,bool>found;
        for(int i=0;i<s.length();i++){
            hash2[s[i]-'a'].push_back(i);
        }
        for(int i=0;i<26;i++){
            int count=0;
            for(int j=0;j<s.length();j++){
                if(s[j]==('a'+i)){
                    count+=1;
                }
                hash[i].push_back(count);
            }

        }
    
        int a=0;
        for(int i=0;i<26;i++){
            if(hash2[i].size()<2){
                continue;
            }
            else{
              
                for(int k=0;k<hash2[i].size()-1;k++){
                    int x=hash2[i][k+1];
                    int y=hash2[i][k];
                    
                    for(int j=0;j<26;j++){
                        if(j!=i){
                           string ans="";
                           ans.push_back('a'+i);
                           ans.push_back('a'+j);
                           ans.push_back('a'+i);  
                       int counter=hash[j][x]-hash[j][y];
                       if(counter>0&&found[ans]==false){

                          found[ans]=true;
                       
                       
                       a+=1;
                       }
                        
                    }
                }
                
            }
        }
        
  


    }
    for(int i=0;i<26;i++){
        if(hash2[i].size()>=3){
            a++;
        }
    }
    return a;
    }
};