class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int j=0;
            int a=0;
            int element=nums[i];
            if(nums[i]==0){
                m[nums[i]]=mapping[0];
            }
            else{
            while(element!=0){
               a=a+(mapping[element%10])*pow(10,j);
               j++;
               element=element/10;
            }
            m[nums[i]]=a;
            }
        }
        auto compare=[&](int c,int b){
            return (m[c]<m[b]);
        };
        sort(nums.begin(),nums.end(),compare);
        return nums;
    }
};