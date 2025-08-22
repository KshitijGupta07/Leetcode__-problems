class Solution {
public:
    vector<int>prev(vector<int>&arr){
        stack<int>st;
        st.push(-1);
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
             while(st.top()!=-1&&arr[st.top()]>arr[i]){
                st.pop();
             }
             ans.push_back(st.top());
             st.push(i);
        }
        return ans;
    }
    vector<int>next(vector<int>&arr){
       stack<int>st;
        st.push(-1);
        vector<int>ans;
        for(int i=arr.size()-1;i>=0;i--){
             while(st.top()!=-1&&arr[st.top()]>=arr[i]){
                st.pop();
             }
             ans.push_back(st.top());
             st.push(i);
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int>nextsmall;
        vector<int>prevsmall;
        nextsmall=next(arr);
        prevsmall=prev(arr);
        long long ans=0;
        long long mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            long long a=prevsmall[i];
            long long b=nextsmall[i];
            
            if(b==-1){
                b=arr.size();
            }
            cout<<a<<" "<<b<<endl;
            long long counter=(long long)(i-a)*(b-i);
            ans=(ans+ (counter*(long long)arr[i])%mod)%mod;
        }
        return ans;

    }
};
