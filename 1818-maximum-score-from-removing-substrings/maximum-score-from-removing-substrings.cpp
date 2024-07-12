class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        stack<char>st;
           
        if(y>x){
   for(int i=0;i<s.length();i++){
            if(st.empty()==true){
               st.push(s[i]);
            }
            else{
                if(st.top()=='b'&&s[i]=='a'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
            

        }
        else{
            for(int i=0;i<s.length();i++){
            if(st.empty()==true){
               st.push(s[i]);
            }
            else{
                if(st.top()=='a'&&s[i]=='b'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        } 
            string ans="";
       
        while(st.empty()==false){
            ans.push_back(st.top());
            st.pop();
        }
    
         reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
        int total=((s.length()-ans.length())/2)*max(x,y);
        for(int i=0;i<ans.length();i++){
            if(st.empty()==true){
                st.push(ans[i]);
            }
            else{
                if(st.top()=='a'&&ans[i]=='b'){
                    st.pop();
                    total+=x;
                }
                else if(st.top()=='b'&&ans[i]=='a'){
                    st.pop();
                    total+=y;
                }
                else{
                    st.push(ans[i]);
                }
            }
        }
        return total;
     
    }
};