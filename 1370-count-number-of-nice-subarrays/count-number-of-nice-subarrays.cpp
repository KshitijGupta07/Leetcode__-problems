class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>prefix;
        map<int,int>m;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                count++;
            }
            prefix.push_back(count);
        }
        m[0]=1;
        count=0;
        for(int i=0;i<nums.size();i++){
            cout<<m[prefix[i]-k]<<endl;
            count+=m[prefix[i]-k];
            m[prefix[i]]++;
        }
        return count;
    }
};