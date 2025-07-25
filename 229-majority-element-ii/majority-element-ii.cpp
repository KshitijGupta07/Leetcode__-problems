class Solution {
public:
    vector<int>majority(vector<int>&nums){
         if(nums.size()==1){
            return nums;
        }
        int element1=pow(10,9)+1;
        int element2=pow(10,9)+1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                element1=nums[i];
                count=1;
            }
            else if(element1==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        count=0;
        for(int i=0;i<nums.size();i++){
               if(count==0){
                if(nums[i]!=element1){
                     element2=nums[i];
                     count=1;
                }
               }
               else if(element2==nums[i]){
                count++;
               }
               else{
                count--;
               }
        }
         count=0;
         int count2=0;
         for(int i=0;i<nums.size();i++){
            if(element1==nums[i]){
                count++;
            }
            if(element2==nums[i]){
                count2++;
            }
         }
         vector<int>temp;
         if(count>nums.size()/3){
            temp.push_back(element1);
         }
         if(count2>nums.size()/3){
            temp.push_back(element2);
         }
        return temp;
    }
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==1){
            return nums;
        }
        int element1=pow(10,9)+1;
        int element2=pow(10,9)+1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                element1=nums[i];
                count=1;
            }
            else if(element1==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        count=0;
        for(int i=0;i<nums.size();i++){
               if(count==0){
                if(nums[i]!=element1){
                     element2=nums[i];
                     count=1;
                }
               }
               else if(element2==nums[i]){
                count++;
               }
               else{
                count--;
               }
        }
        count=0;
         int count2=0;
         for(int i=0;i<nums.size();i++){
            if(element1==nums[i]){
                count++;
            }
            if(element2==nums[i]){
                count2++;
            }
         }
         vector<int>temp;
         if(count>nums.size()/3){
            temp.push_back(element1);
         }
         if(count2>nums.size()/3){
            temp.push_back(element2);
         }
         reverse(nums.begin(),nums.end());
         vector<int>temp2=majority(nums);
         if(temp.size()==2){
            return temp;
         }
         if(temp2.size()==2){
            return temp2;
         }
          
         if(temp.size()==1&&temp2.size()==1){
            if(temp[0]!=temp2[0]){
                temp.push_back(temp2[0]);
            }
         }
         if(temp.size()==0){
            return temp2;
         }
         return temp;
    }
};