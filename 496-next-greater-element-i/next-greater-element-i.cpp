class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        stack<int>st;
        st.push(-1);
        for(int i=nums2.size()-1;i>=0;i--){
            while(st.empty()==false&&st.top()!=-1&&nums2[st.top()]<nums2[i]){
                st.pop();
            }
            if(st.top()==-1){
                m[nums2[i]]=-1;
            }
            else{
                m[nums2[i]]=nums2[st.top()];
                
            }
            st.push(i);

        }
        vector<int>ans;
        for(auto j:nums1){
            ans.push_back(m[j]);
        }
        return ans;
    }
};