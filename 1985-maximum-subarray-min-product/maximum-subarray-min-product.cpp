class Solution {
public:
    void pes(vector<int>&nums,vector<int>&prev){
        stack<int>st;
        st.push(-1);
        for(int i=0;i<nums.size();i++){
            while(st.top()!=-1&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            int ans=st.top();
            prev[i]=ans;
            st.push(i);
        }
    }
    void nes(vector<int>&nums,vector<int>&next){
        stack<int>st;
        st.push(nums.size());
          for(int i=nums.size()-1;i>=0;i--){
            while(st.top()!=nums.size()&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            int ans=st.top();
            next[i]=ans;
            st.push(i);
          }
    }
    int maxSumMinProduct(vector<int>& nums) {
        vector<int>prev(nums.size(),-1);

        vector<int>next(nums.size(),nums.size());
        pes(nums,prev);
        nes(nums,next);
        long long mod=pow(10,9)+7;
        vector<long long>prefix(nums.size());
        prefix[0]=nums[0]%mod;
        for(int i=1;i<prefix.size();i++){
            
            prefix[i]=(prefix[i-1]+nums[i]);
        
        }
        
        long long  maxans=0;
        for(int i=0;i<prefix.size();i++){
            long long  ans=0;
            ans+=prefix[next[i]-1];
            if(prev[i]>=0){
            ans-=prefix[prev[i]];
            }
            long long element=nums[i];
            ans=(ans*element);
            maxans=max(maxans,ans);
        }
        return maxans%mod;
    }
};