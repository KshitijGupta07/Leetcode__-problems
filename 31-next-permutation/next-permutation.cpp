class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int a=-1;
        int b=-1;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                   if(nums[i]<nums[j]){
                    a=i;
                    b=j;
                   }
            }
        }
        if(a==-1&&b==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        else{
            swap(nums[a],nums[b]);
        }
        cout<<a<<" "<<b<<endl;
        for(int i=a+1;i<nums.size()-1;i++){
            int index=-1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[i]){
                    index=j;
                }
            }
            if(index!=-1){
                swap(nums[index],nums[i]);
            }
        }

          
    }
};