class KthLargest {
public:
  int a=0;
   priority_queue<int,vector<int>,greater<int>>p;
    KthLargest(int k, vector<int>& nums) {
        int i=0;
        a=k;
        while(p.size()<k&&i<nums.size()){

            p.push(nums[i]);
            
            i++;
        } 
        for(int x=i;x<nums.size();x++){
               if(p.top()<=nums[x]){
                p.pop();
                p.push(nums[x]);
               }
        }
    }
    
    int add(int val) {
        
        if(p.empty()){
            p.push(val);
            
        }
        else if(p.size()<a){
            p.push(val);
        }
       else if(p.top()<=val){
            p.pop();
            p.push(val);
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */