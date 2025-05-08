class Solution {
public:
   void heapify(vector<pair<int,int>>&v,int i,int n){
     int large=i;
     int left=2*i +1;
     int right=2*i +2;
     if(left<n&&v[left].first>v[large].first){
        large=left;
     }
     if(right<n&&v[right].first>v[large].first){
        large=right;
     }
     
     if(large!=i){
        swap(v[large],v[i]);
        heapify(v,large,n);
     }
   }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto j:nums){
            m[j]++;
        }
        vector<pair<int,int>>v;
        
        for(auto j:m){
            v.push_back({j.second,j.first});
        }
        int n=v.size();
        for(int i=n/2 -1;i>=0;i--){
            heapify(v,i,v.size());
        }
       
        vector<int>ans;
        ans.push_back(v[0].second);
        for(int i=n-1;i>n-k;i--){
              

                 swap(v[0],v[i]);
                  
                 heapify(v,0,i);
                 
                  cout<<"next"<<endl;
                 ans.push_back(v[0].second);
        }
        return ans;
    }
};