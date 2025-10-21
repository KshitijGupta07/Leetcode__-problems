class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int>s;
        for(auto j:nums){
            s.insert(j);
        }
        int ans=1;
        for(auto j:s){
            if(s.find(j-1)==s.end()){
                  int temp=j+1;
                  int count=1;
                  while(s.find(temp)!=s.end()){
                       temp++;
                       count++;
                  }
                  ans=max(ans,count);
            }
        }
        return ans;
    }
};