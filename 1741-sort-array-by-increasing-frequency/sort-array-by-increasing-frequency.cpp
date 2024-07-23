class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>f;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }
        vector<pair<int,int>>ans;
        for(auto j:f){
            ans.push_back({j.second,j.first});
        }
        auto compare=[&](pair<int,int>a,pair<int,int >b){
              if(a.first==b.first){
                return a.second>b.second;
              }
              return a.first<b.first;
        };
        sort(ans.begin(),ans.end(),compare);
        for(auto j:ans){
            cout<<j.first<<" "<<j.second<<endl;
        }
        int j=0;
        for(int i=0;i<ans.size();i++){
            while(ans[i].first!=0){
                nums[j]=ans[i].second;
                j++;
                ans[i].first--;
            }
        
        }
        return nums;
    }
};