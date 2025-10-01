class Solution {
public:
    vector<int>prev(vector<int>&temp){
         stack<int>st;
         st.push(-1);
         vector<int>ans;
         for(int i=0;i<temp.size();i++){
             while(st.top()!=-1&&temp[st.top()]>=temp[i]){
            st.pop();
             }
             ans.push_back(st.top());
             st.push(i);
         }
         return ans;
    }
    vector<int>next(vector<int>&temp){
         stack<int>st;
         st.push(-1);
         vector<int>ans;
         for(int i=temp.size()-1;i>=0;i--){
             while(st.top()!=-1&&temp[st.top()]>=temp[i]){
            st.pop();
             }
             ans.push_back(st.top());
             st.push(i);
         }
         reverse(ans.begin(),ans.end());
         for(int i=0;i<ans.size();i++){
            if(ans[i]==-1){
                ans[i]=ans.size();
            }
         }
         return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
         vector<int>temp;
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i]=='0'){
                temp.push_back(0);
            }
            else{
                temp.push_back(1);
            }
        }
        vector<int>p=prev(temp);
        vector<int>n=next(temp);
        for(int i=0;i<matrix[0].size();i++){
            int x=matrix[0][i]-'0';
            cout<<p[i]<<" "<<n[i]<<endl;
            ans=max(ans,x*(n[i]-p[i]-1));
        }
       
        for(int i=1;i<matrix.size();i++){
            
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='0'&&matrix[i-1][j]=='1'){
                   temp[j]=0;
                }
                else if(matrix[i][j]=='1'&&(matrix[i-1][j]=='0'||matrix[i-1][j]=='1')){
                    int x=temp[j];
                    x=x+1;
                    temp[j]=x;
                }
            }
            for(auto j:temp){
                cout<<j<<" ";
            }
            cout<<endl;
            p=prev(temp);
            n=next(temp);
            for(int j=0;j<temp.size();j++){
                int x=temp[j];
                cout<<n[j]<<" "<<p[j]<<endl;
                ans=max(ans,x*(n[j]-p[j]-1));
            }
        }
        return ans;
    }
};