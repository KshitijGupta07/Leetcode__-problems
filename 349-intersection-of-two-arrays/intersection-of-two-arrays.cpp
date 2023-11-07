class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
                   while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums2[j]);
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        if(ans.size()!=0){
        for(int i=0;i<ans.size()-1;){
            if(ans[i]==ans[i+1]){
                ans.erase(ans.begin()+i+1);
            }
            else{
                i++;
            }
        }
    }
        return ans;

    }
};