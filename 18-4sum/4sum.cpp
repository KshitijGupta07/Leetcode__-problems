class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){
            return {};
        }
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                int start=j+1;
                int end=nums.size()-1;
                long long  su=nums[i]+nums[j];
                
               bool check=false;
                while(start<end){
                      long long su2=nums[start]+nums[end];
                    if(su+su2==target){
                        
                         ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                        
                        
                         start++;
                         end--;
                    }
                    else if(su+nums[start]+nums[end]>target){
                        end--;
                    }
                    else{
                        start++;
                    }

                }

            }
        }
        if(ans.empty()==true){
            return {};
        }
        vector<vector<int>>finalans;

        finalans.push_back(ans[0]);
        for(int i=1;i<ans.size();i++){
            if(finalans.back()==ans[i]){
                continue;
            }
            else{
                finalans.push_back(ans[i]);
            }
        }
        return finalans;
    }
};