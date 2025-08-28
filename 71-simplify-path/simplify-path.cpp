class Solution {
public:
    string simplifyPath(string path) {
        vector<string>temp;
        string x="";
        for(int i=0;i<path.length();i++){
            if(path[i]!='/'){
                  x.push_back(path[i]);
            }
            else{
                if(x!=""){
                    temp.push_back(x);
                    x="";
                }

            }
           
        }
        if(x!="")
        temp.push_back(x);
        stack<string>st;
    
        for(int i =0;i<temp.size();i++){
              if(st.empty()==true&&(temp[i]!=".."&&temp[i]!=".")){
                      st.push(temp[i]);
              }
               else{
                  if(st.empty()==false&&temp[i]==".."){
                    st.pop();
                  }
                else if(st.empty()==true&&temp[i]==".."){
                    continue;
                  }
                  else if(temp[i]!="."){
                    st.push(temp[i]);
                  }
               }
         
        }
         string answer="/";
         temp.clear();
          
        while(st.empty()==false){
            
        
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(auto j:temp){
            answer+=j;
            answer.push_back('/');
        }
       if(answer.length()==1){
        return answer;
       }
        answer.pop_back();
       
        return answer;
        
    }
};