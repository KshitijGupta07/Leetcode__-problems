class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st;
        st.push(directions[0]);
        if(directions.length()==1){
            return 0;
        }
        int count=0;
        for(int i=1;i<directions.length();i++){
              if(directions[i]=='L'&&st.top()=='R'&&st.empty()==false){
                    count+=2;
                    st.pop();
                    st.push('S');
              }
              else if(directions[i]=='S'&&st.top()=='R'&&st.empty()==false){
                count+=1;
                st.pop();
                st.push('S');
              }
              else if(directions[i]=='L'&&st.top()=='S'&&st.empty()==false){
                count+=1;
                st.pop();
                st.push('S');
              }
              else{
               st.push(directions[i]);
              }
        }
         while(st.top()=='R'&&st.empty()==false){
                    st.pop();
                
            
                  
                    
                
                
                
                }
                  while(st.empty()==false){
                        if(st.top()=='R')
                        count++;
                        st.pop();
                    }
        return count;
    }
};