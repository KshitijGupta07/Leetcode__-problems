class FindSumPairs {
public:
    map<int,int>m;
    vector<int>nums;
    vector<int>temp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
       temp=nums1;
        nums=nums2;
        for(auto j:nums){
            m[j]+=1;
        }
    }
    
    void add(int index, int val) {
        m[nums[index]]-=1;
        nums[index]+=val;
        m[nums[index]]+=1;

    }
    
    int count(int tot) {
        int count=0;
        
    
       for(auto j:temp){
        
         count+=m[tot-j];
       } 
       
       return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */