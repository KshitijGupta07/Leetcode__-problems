class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        deque<int>d;
        vector<int>ans;
        while(r<nums.size()){
                while(d.empty()==false&&d.back()<nums[r]){
                    d.pop_back();
                }
                d.push_back(nums[r]);
                if(r-l+1==k){
                    int front=d.front();
                    ans.push_back(front);
                    if(nums[l]==front){
                          d.pop_front();
                    }
                    l++;
                }
                r++;
        }
        return ans;
    }
};