class KthLargest {
public:
  priority_queue<int,vector<int>,greater<int>>p;
  int x;
    KthLargest(int k, vector<int>& nums) {
        x=k;
        for(int i=0;i<nums.size();i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if(p.size()<x||p.top()<val){
            p.push(val);
            if(p.size()>x){
                p.pop();
            }
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */