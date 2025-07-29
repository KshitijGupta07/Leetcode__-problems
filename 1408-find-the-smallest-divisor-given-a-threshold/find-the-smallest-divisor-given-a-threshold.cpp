class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()==1){
            return nums[0]/threshold +min(1,nums[0]%threshold);
        }
        int maxi=0;
        for(auto j:nums){
            maxi=max(maxi,j);
        }
        int start=1;
        int end=maxi;
        while(start<=end){
            int mid=(start+end)/2 ;
            
            int sum=0;
            for(int i=0;i<nums.size();i++){
                int a=(nums[i]/mid)+min(1,nums[i]%mid);
                sum+=a;
            }
            
            if(sum>threshold){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        int a=0;
        int b=0;
        if(end==0){
            return start;
        }
         for(int i=0;i<nums.size();i++){
            a=a+(nums[i]/start)+min(1,nums[i]%start);
            b=b+(nums[i]/end)+min(1,nums[i]%end);
         }
        if(a<=threshold&&b<=threshold){
            if(a>b){
                return start;
            }
            else if(a<b){
                return end;
            }
            else{
                return min(start,end);
            }
        }
        else if(a<=threshold&&b>threshold) return start;
        else if(a>threshold&&b<=threshold)return end;
        
        return -1;
    }
};