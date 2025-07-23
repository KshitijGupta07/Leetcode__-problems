class Solution {
public:
    int maximumGain(string s, int x, int y) {
    
        int ans=0;
        string st="";
        if(x>y){
        for(int i=0;i<s.length();i++){
              if(st.empty()==true){
                st.push_back(s[i]);
              }
              else{
                  if(st.back()=='a'&&s[i]=='b'){
                    st.pop_back();
                    ans+=x;
                  }
                  else{
                    st.push_back(s[i]);
                  }
              }
        }
        }
        else{
              for(int i=0;i<s.length();i++){
              if(st.empty()==true){
                st.push_back(s[i]);
              }
              else{
                  if(st.back()=='b'&&s[i]=='a'){
                    st.pop_back();
                    ans+=y;
                  }
                  else{
                    st.push_back(s[i]);
                  }
              }
        }
        }
        if(st.size()==1||st.size()==0){
            return ans;
        }
        cout<<ans<<" "<<st<<endl;
        string temp="";
        for(int i=0;i<st.length();i++){
              if(temp.empty()==true){
                temp.push_back(st[i]);
              }
              else{
                if(temp.back()=='a'&&st[i]=='b'){
                    temp.pop_back();
                    ans+=x;
                }
                else if(temp.back()=='b'&&st[i]=='a'){
                    ans+=y;
                    temp.pop_back();
                }
                else{
                    temp.push_back(st[i]);
                }
              }
        }
        return ans;
        
        
    }
};