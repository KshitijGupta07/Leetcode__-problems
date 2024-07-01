class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left=0;
        int right=0;
        int maxlen=0;
multiset<int>window;
        while(right<nums.size()){
            window.insert(nums[right]);
            if(*window.rbegin()-*window.begin()>limit){
                window.erase(window.find(nums[left]));
              
            left++;
            }
            

              int length=right-left+1;
            maxlen=max(maxlen,length);
            right++;
            
          
        }
        return maxlen;
    }
};