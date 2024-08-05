class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int count=0;
        while(maxi!=0){
            maxi=maxi>>1;
            count++;
        }
        vector<pair<int,int>>p;
        for(int i=0;i<count;i++){
            int a=0;
            int b=0;
            for(int j=0;j<nums.size();j++){
                int element=nums[j];
               if(((element>>i)&1)==1){
                a++;
               }
               else{
                b++;
               }
            }
            p.push_back({a,b});
        }
        int ans=0;
        for(auto j:p){
          ans+=(j.first)*(j.second);
        }
        return ans;
    }
};