class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<int>st;
        vector<int>index;
        int n=directions.length();
        for(int i=0;i<n;i++){
            index.push_back(i);
        }
        auto compare=[&](int index1,int index2){
            return positions[index1]<=positions[index2];
        };
        sort(index.begin(),index.end(),compare);
        for(int i=0;i<n;i++){
            if(st.empty()==true){
                if(directions[index[i]]=='R'){
                st.push(index[i]);
                }
            }
            else{
                if(directions[index[i]]=='R'){
                    st.push(index[i]);
                }
                else{
                    while(st.empty()==false&&healths[index[i]]>0){
                    if(healths[st.top()]>healths[index[i]]){
                        healths[st.top()]--;
                        healths[index[i]]=0;
                    }
                    else if(healths[st.top()]<healths[index[i]]){
                        healths[st.top()]=0;
                        healths[index[i]]--;
                        st.pop();
                    }
                    else{
                        healths[st.top()]=0;
                        healths[index[i]]=0;
                        st.pop();
                    }
                    }

                }
            }
        }
        vector<int>ans;
        for(int i=0;i<healths.size();i++){
            if(healths[i]!=0)
              ans.push_back(healths[i]);
        }
        return ans;

    }
};