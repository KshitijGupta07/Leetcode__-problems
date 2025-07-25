class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefix;
        int sum=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
             sum+=nums[i];
             prefix.push_back(sum);
            
        }
        m[0]=1;
        int count=0;
        for(int i=0;i<prefix.size();i++){
            
    
                if(m[prefix[i]-k]>0){
                    count+=m[prefix[i]-k];
                }
            
            m[prefix[i]]++;
        }
        
        return count;


    }
};