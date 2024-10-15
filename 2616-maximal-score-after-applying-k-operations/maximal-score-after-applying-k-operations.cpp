class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int>p;
        for(int i=0;i<nums.size();i++){
            p.push(nums[i]);
        }
        while(k>0){
            long long  a=p.top();
            p.pop();
            ans+=a;
         if(a%3==0){
            p.push(a/3);
         }
         else{
            p.push(a/3 +1);
         }
            k--;
        }
        return ans;
    }
};