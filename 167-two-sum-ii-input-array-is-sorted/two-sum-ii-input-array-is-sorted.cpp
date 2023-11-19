class Solution {
public:
   int binary_search(vector<int>& numbers,int target){
       int start=0;
       int end=numbers.size()-1;
       while(start<=end){
           int mid=start+(end-start)/2;
           if(numbers[mid]==target){
               return mid;
               break;
           }
           else if(numbers[mid]>target){
               end=mid-1;

           }
           else{
               start=mid+1;
           }
       }
       return -1;
   }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        for(int i=0;i<numbers.size();i++){
            if(binary_search(numbers,target-numbers[i])!=-1){
                ans.push_back(i+1);
                ans.push_back(binary_search(numbers,target-numbers[i])+1);
                break;
            }
        }
        if(ans[0]==ans[1]){
            ans[1]=ans[1]+1;
        }
        return ans;
        
    }
};