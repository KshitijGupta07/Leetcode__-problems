class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        if(nums.size()<4){
            return ans;
        }
        else{
            for(int start=0;start<nums.size()-3;start++){
                 if (start > 0 && nums[start] == nums[start - 1])
                continue;
                for(int second=start+1;second<nums.size()-2;second++){
                    if(second>start+1&&nums[second]==nums[second-1])continue;
                    long sum=long(nums[start]+nums[second]);
                    int s=second+1;
                    int e=nums.size()-1;
                    while(s<e){
                        if(long(nums[s]+nums[e])==long(target-sum)){
                        
                            
                            ans.push_back({nums[s],nums[e],nums[start],nums[second]});
                            int low=nums[s];
                            int high=nums[e];
                            s++;
                            e--;
                            cout<<nums[s]<<" "<<nums[e]<<""<<nums[second]<<" "<<nums[start]<<endl;
                            
                            
                        }
                        else if(long(nums[s]+nums[e])>long(target-sum)){
                            e--;
                        }
                        else{
                            s++;
                        }
                    }
                }
            }
            
        }
        if(ans.size()==0){
            return {};
        }
        
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size()-1;){
            if(ans[i]==ans[i+1]){
                ans.erase(ans.begin()+i+1);
            }
            else{
                i++;
            }
        }
        return ans;
    }
};