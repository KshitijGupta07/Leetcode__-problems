class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>prefix;
        map<int,int>m;
        int element=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]<0){
                nums[i]=nums[i]%k+k;
             }
             element+=nums[i];
             prefix.push_back(element%k);
        }
        for(int i=0;i<prefix.size();i++){
            count+=m[prefix[i]];
            m[prefix[i]]++;
            if(prefix[i]==0){
                count++;
            }
            
        }
        return count;

    }
};