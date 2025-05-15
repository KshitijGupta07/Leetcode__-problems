class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!=' '&&isdigit(s[i])==false&&s[i]!='-'&&s[i]!='+'){
                break;
                
            }
            else{
                if(isdigit(s[i])){
                ans.push_back(s[i]);
                }
                if(s[i]=='-'){
                    
                    if(ans.length()>0){
                        break;
                    }
                    else{
                        ans.push_back(s[i]);
                    }
                }
                 if(s[i]=='+'){
                    if(ans.length()>0){
                        break;
                    }
                    else{
                        ans.push_back(s[i]);
                    }
                }
               
                if(s[i]=='0'){
                    if(ans.length()==0){
                        continue;
                    }
                }
                if(s[i]==' '){
                    if(ans.length()>0){
                        break;
                    }
                }
            }

        }
        
        string x="";
    
        for(int i=0;i<ans.length();i++){
            
            if(isdigit(ans[i])){
                x.push_back(ans[i]);
            }
            if(x.length()>0&&stoll(x)>INT_MAX){
                if(ans[0]=='-'){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }
            }
            
        }
        cout<<x<<endl;
        if(ans.length()==0){
            return 0;
        }
        if(ans.length()==1){
            if(ans[0]=='+'||ans[0]==
            '-'){
                return 0;
            }
        }
        if(ans[0]=='-'){
            return -stoi(x);
        }

        return stoi(x);
    }
};