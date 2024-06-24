class Solution {
public:
void solve(vector<vector<int>>&ans,vector<int>output,vector<int>sum,int k,int n,int index){
    if(index==sum.size()){
        return;
    }
    if(n==0){
        if(output.size()==k){
            for(int i=0;i<k;i++){
                if(output[i]>9){
                    return;
                }
            }
            ans.push_back(output);
        }
        return;
    }
    for(int i=index;i<sum.size();i++){
        if(sum[i]>n){
            break;
        }
        output.push_back(sum[i]);
        solve(ans,output,sum,k,n-sum[i],i+1);
        output.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>sum;
       
        for(int i=1;i<=10;i++){
            sum.push_back(i);
        }
        vector<vector<int>>ans;
         if(n>45){
            return ans;
        }
        
        vector<int>output;
        int index=0;
        solve(ans,output,sum,k,n,index);
        // if(n==45&&k==9){
        //     ans.push_back({1,2,3,4,5,6,7,8,9});
        // }
        return ans;
    }
};