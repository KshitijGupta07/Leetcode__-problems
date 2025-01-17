class Solution {
public:
    bool check(vector<int>&nums,vector<vector<int>>&queries,int mid){
        vector<int>v(nums.size()+1,0);
        int x=queries.size()-1;
        int sum=0;
       
        cout<<sum<<endl;
        
        for(int i=0;i<=min(mid,x);i++){
            
            int a=queries[i][0];
            int b=queries[i][1];
            int c=queries[i][2];
            v[a]+=c;
            v[b+1]-=c;
        }
        for(int i=1;i<v.size();i++){
              v[i]+=v[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]-v[i]<=0){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum=0;
        for(auto j:nums){
            sum+=j;
        }
        if(sum==0){
            return 0;
        }
        int start=0;
        int end=queries.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            cout<<mid<<endl;
            if(check(nums,queries,mid)){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        if(start<queries.size()){
            return start+1;
        }
        return -1;
        
        
       
    }
};