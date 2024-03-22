class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int a=-1;
        int b=-1;
          vector<int>ans;
        for(int i=0;i<nums.size();i++){
             if(nums[i]<0){
                a=i;
             }
             if(nums[i]>=0){
                b=i;
                break;
             }
        }
        if(a==-1){
            for(int i=0;i<nums.size();i++){
                nums[i]*=nums[i];
            }
            return nums;
        }
        if(b==-1){
            for(int i=nums.size()-1;i>=0;i--){
                ans.push_back(nums[i]*nums[i]);
                
            }
            return ans;
        }
        if(a!=-1&&b!=-1){
        while(a>-1&&b<nums.size()){
             if(nums[a]*nums[a]<nums[b]*nums[b]){
                ans.push_back(nums[a]*nums[a]);
                  a--;
             }
             else{
                ans.push_back(nums[b]*nums[b]);
                b++;
             }
        }
        cout<<a<<" "<<b<<endl;
        if(b==nums.size()-1){
        ans.push_back(nums[b]*nums[b]);
        b++;
        }
        
        if(a==0){
            ans.push_back(nums[a]*nums[a]);
        }
        if(a>0){
            while(a>-1){
                 ans.push_back(nums[a]*nums[a]);
                 a--;
            }
        }
        if(b<nums.size()-1){
            while(b<nums.size()){
                  ans.push_back(nums[b]*nums[b]);
                  b++;
            }
        }
       
        
    }
    return ans;     
        

    }
};