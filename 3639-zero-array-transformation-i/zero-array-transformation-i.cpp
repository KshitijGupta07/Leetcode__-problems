class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>v(nums.size()+1,0);
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            v[a]++;
            v[b+1]--;
        }
        for(int i=1;i<v.size();i++){
            v[i]+=v[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]-v[i]<=0){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};