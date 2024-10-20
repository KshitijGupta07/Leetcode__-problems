class Solution {
public:
    int operations(vector<int>&nums){
         int count=0;
        int minindex=0;
        for(int i=1;i<nums.size();i++){
            if(nums[minindex]>nums[i]){
                minindex=i;
            }
        }

         for(int i=minindex-1;i>=0;i--){
               
                bool signal=false;
                for(int j=2;j<=sqrt(nums[i]);j++){
                    if(nums[i]%j==0){
                        nums[i]=j;
                        if(j>nums[minindex]){
                            return -1;
                            
                        }
                        signal=true;
                        count=count+1;
                        break;
                    }
                }
                if(signal==false){
                    return -1;
                }
               
         }
         for(int i=nums.size()-2;i>=minindex;i--){
            if(nums[i+1]<nums[i]){
                bool signal=false;
                for(int j=2;j<=sqrt(nums[i]);j++){
                     if(nums[i]%j==0){
                        nums[i]=j;
                        if(j>nums[i+1]){
                            return -1;
                            
                        }
                        signal=true;
                        count=count+1;
                        break;
                    }
                }
                if(signal==false){
                   return -1;
                }
            }
         }
         for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                return -1;
            }
         }
        return count;
    }
    int minOperations(vector<int>& nums) {
        int count=0;
        int minindex=0;
          vector<int>a=nums;
        for(int i=1;i<nums.size();i++){
            if(nums[minindex]>nums[i]){
                minindex=i;
            }
        }
              int count2=operations(a);
         for(int i=0;i<minindex;i++){
               
                bool signal=false;
                for(int j=2;j<=sqrt(nums[i]);j++){
                    if(nums[i]%j==0){
                        nums[i]=j;
                        if(j>nums[minindex]){
                            return -1;
                            
                        }
                        signal=true;
                        count=count+1;
                        break;
                    }
                }
                if(signal==false){
                    return -1;
                }
               
         }
         for(int i=minindex;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                bool signal=false;
                for(int j=2;j<=sqrt(nums[i]);j++){
                     if(nums[i]%j==0){
                        nums[i]=j;
                        if(j>nums[i+1]){
                            return -1;
                            
                        }
                        signal=true;
                        count=count+1;
                        break;
                    }
                }
                if(signal==false){
                   return -1;
                }
            }
         }
           
         for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                if(count2==-1){
                    return -1;
                }
                else{
                    return count2;
                }
            }
         }
         
       
        return count;
    }
};