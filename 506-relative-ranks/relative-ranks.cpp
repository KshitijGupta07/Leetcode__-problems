class Solution {
public:
    int binarysearch(vector<int>&a,int target){
        int  start=0;
        int end=a.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(a[mid]==target){
                return mid+1;
                break;
            }
            else if(a[mid]>target){
               start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return  -1;
    }
    vector<string> findRelativeRanks(vector<int>& score){
        
          vector<string>ans;
          vector<int>a;
          for(int i=0;i<score.size();i++){
              a.push_back(score[i]);
          }
          sort(a.begin(),a.end());
          reverse(a.begin(),a.end());
          
        
          for(int i=0;i<score.size();i++){
              if(binarysearch(a,score[i])==1){
                  ans.push_back("Gold Medal");
                  
              }
              else if(binarysearch(a,score[i])==2){
                  ans.push_back("Silver Medal");
              }
              else if(binarysearch(a,score[i])==3){
                  ans.push_back("Bronze Medal");
              }
              else{
                  ans.push_back(to_string(binarysearch(a,score[i])));
              }
          }
         return ans; 

    }
};