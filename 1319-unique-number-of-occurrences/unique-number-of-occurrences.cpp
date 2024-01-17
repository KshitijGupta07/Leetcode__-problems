class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       sort(arr.begin(),arr.end());
       int count=1;
       vector<int>ans;
       for(int i=0;i<arr.size()-1;i++){
           if(arr[i]==arr[i+1]){
               count++;
           }
           else{
               ans.push_back(count);
               count=1;
           }
    }
    ans.push_back(count);
      sort(ans.begin(),ans.end());
          for(int i=0;i<ans.size()-1;i++){
              if(ans[i]==ans[i+1]){
                  return false;
              }
          }
          return true;
      }
       
    
};