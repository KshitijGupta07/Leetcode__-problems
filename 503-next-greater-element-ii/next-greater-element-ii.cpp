class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans=nums;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        vector<int>m;
        
        stack<int>st;
        st.push(-1);
        for(int i=ans.size()-1;i>=0;i--){
              while(st.top()!=-1&&ans[st.top()%nums.size()]<=nums[i%nums.size()]){
                   st.pop();
              }
              if(i<nums.size()){
              if(st.top()==-1){
                  m.push_back(-1);
              }
              else{
                m.push_back(nums[st.top()%nums.size()]);
              }
              }
              st.push(i%nums.size());
        }
        reverse(m.begin(),m.end());
        return m;
    }
};