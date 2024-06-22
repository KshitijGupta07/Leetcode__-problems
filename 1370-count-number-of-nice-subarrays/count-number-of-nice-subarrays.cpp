class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k){
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]%2;
        }
        
        int element=0;
        for(int i=0;i<nums.size();i++){
           element+=nums[i];
           mp[element]++;
        }
        int count=0;
      
        for(auto j:mp){
            if(j.first==k){
                if(mp[0]!=0){
                count+=j.second*mp[0];
            }
            
                count+=j.second;
            
            
        }
        if(j.first>k&&mp[j.first-k]!=0){
            count+=j.second*mp[j.first-k];
        }
        
        }
        return count;
    }
};