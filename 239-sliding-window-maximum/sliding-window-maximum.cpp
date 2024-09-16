class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d;
        vector<int>ans;
        int l=0;
        int r=0;
        while(r<nums.size()){
            while(d.empty()==false&&d.back()<nums[r]){
                d.pop_back();
            }
            d.push_back(nums[r]);
            if(r-l+1==k){
                int a=d.front();
               if(d.front()==nums[l]){
                  d.pop_front();
               }
               ans.push_back(a);
               l++;
            }
            r++;
        }
        return ans;
    }
};