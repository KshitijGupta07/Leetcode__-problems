class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,bool>m;
        unordered_map<int,int>mp;
         for(auto j:nums2){
            m[j]=true;
         }
        stack<int>st;
        st.push(-1);
        for(int i=nums2.size()-1;i>=0;i--){
            while(st.top()!=-1&&nums2[st.top()]<nums2[i]){
                st.pop();
            }
            if(st.top()==-1){
                mp[nums2[i]]=-1;
            }
            else{
                mp[nums2[i]]=nums2[st.top()];
            }
            st.push(i);

        }
        for(int i=0;i<nums1.size();i++){
            if(m[nums1[i]]){
                ans.push_back(mp[nums1[i]]);
            }
        }
        return ans;
    }
};