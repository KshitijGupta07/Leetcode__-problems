class Solution {
public:
    int binarysearch(vector<int>&ans,int target){
        int start=0;
        int end=ans.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(ans[mid]==target){
                return ans[mid];
            }
            else if(ans[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        if(start==ans.size()){
            return ans[start-1];
        }
        return ans[start];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if(intervals.size()==1){
            if(intervals[0][0]==intervals[0][1]){
            return {0};
            }
            else{
                return {-1};
            }
        }
        map<int,int>mpp;
        vector<int>ans;
        for(int i=0;i<intervals.size();i++){
            mpp[intervals[i][0]]=i;
            ans.push_back(intervals[i][0]);
        }
        sort(ans.begin(),ans.end());
         int a=0;
         vector<int>c;
        for(int i=0;i<intervals.size();i++){
            int element=binarysearch(ans,intervals[i][1]);
            if(element<intervals[i][1]){
                
               c.push_back(-1);
            }
            else{
               
            c.push_back(mpp[element]);
            }
            
        }
        cout<<endl;
        return c;
       
    }
};