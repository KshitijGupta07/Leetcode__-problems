class Solution {
public:
  vector<int>major(vector<int>&nums){
    int element1=INT_MAX;
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
        int element2=INT_MAX;
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
        int counter=0;
        int counter2=0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]==element2){
                counter++;
             }
             if(nums[i]==element1){
                counter2++;
             }
        }
        vector<int>ans;
         cout<<element1<<" "<<element2<<endl;
         if(counter>nums.size()/3){
            ans.push_back(element2);
         }
         if(counter2>nums.size()/3){
            if(element2!=element1){
                ans.push_back(element1);
            }
         }

        
        return ans;
  }
    vector<int> majorityElement(vector<int>& nums) {
        int element1=INT_MAX;
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
        int element2=INT_MAX;
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
        int counter=0;
        int counter2=0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]==element2){
                counter++;
             }
             if(nums[i]==element1){
                counter2++;
             }
        }
        vector<int>ans;
         
         if(counter>nums.size()/3){
            ans.push_back(element2);
         }
         if(counter2>nums.size()/3){
            if(element2!=element1){
                ans.push_back(element1);
            }
         }
         reverse(nums.begin(),nums.end());
          vector<int>ans2=major(nums);
        
            if(ans.size()>ans2.size()){
                return ans;
            }
            else{
                return ans2;
            }
         
        
        return {};
    }
};