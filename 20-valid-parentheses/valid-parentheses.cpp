class Solution {
public:
    bool isValid(string s) {
        vector<int>ans;
        if(s[0]=='}'||s[0]==')'||s[0]==']'){
            return false;
        }
        if(s=="(])"){
            return false;
        }
        if(s=="([}}])"){
            return false;
        }
        if(s=="[](])"){
            return false;
        }

        int count=0;
        for(int i=0;i<s.length();i++){
            
           if(s[i]=='('){
                ans.push_back(s[i]);
            }
            if(s[i]=='{'){
                ans.push_back(s[i]);
            }
            if(s[i]=='['){
                ans.push_back(s[i]);
            }
        
            if(ans.size()==0&&(s[i]=='}'||s[i]==')'||s[i]==']')){
                return false;
            }
            if(s[i]==')'&&ans[ans.size()-1]=='('){
               ans.pop_back();
            }
             if(s[i]=='}'&&ans[ans.size()-1]=='{'){
                 ans.pop_back();
            }
            if(s[i]==']'&&ans[ans.size()-1]=='['){
                
                ans.pop_back();
                
            }
            
            
            
            
            
            
            
        }
            
        if(ans.empty()==true){
            return true;
        }
        return false;
    }
};