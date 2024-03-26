class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>hash(pow(10,5));
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]==2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};