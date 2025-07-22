class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>m;
        int l=0;
        int r=0;
        int sum=0;
        int ans=0;
        while(r<nums.size()){
            if(m[nums[r]]==0){
            
               m[ nums[r]]=1;
                sum+=nums[r];
                r++;
            }
            else{
            cout<<sum<<endl;
              m[nums[l]]-=1;
              ans=max(ans,sum);
              sum=sum-nums[l];
              l++;

            }
            
           
        }
    
        return max(ans,sum);
    }
};