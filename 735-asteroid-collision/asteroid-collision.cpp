class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty()==true){
               st.push(asteroids[i]);
            }
            else{
                if(asteroids[i]<0){
              while(st.empty()==false&&st.top()>0&&st.top()<abs(asteroids[i])){
                
                st.pop();
              }
               if(st.empty()==false){
                
                if(st.top()>0&&st.top()==abs(asteroids[i])){
            
                    st.pop();
                }
                else if(st.top()>0&&st.top()>abs(asteroids[i])){
                    continue;
                }
                else{
                    st.push(asteroids[i]);
                }
                
               }
               else{
                st.push(asteroids[i]);
               }
                
                }
                else{
                    st.push(asteroids[i]);
                }
            }
        }
        while(st.empty()==false){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};