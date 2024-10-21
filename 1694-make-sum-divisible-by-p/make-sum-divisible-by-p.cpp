class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<int>prefix;
        int element=0;
        for(int i=0;i<nums.size();i++){
            element+=nums[i];
            element=element%p;
        }
        element=element%p;
        if(element==0){
            return 0;
        }
        
        unordered_map<int,int>visited;
        visited[0]=-1;
        int length=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%p;
            int need=(sum-element+p)%p;
            if(visited.find(need)!=visited.end()){
                length=min(length,i-visited[need]);
            }
            visited[sum]=i;
        }
        if(length==nums.size()){
            return -1;
        }
        return length;
    }
};