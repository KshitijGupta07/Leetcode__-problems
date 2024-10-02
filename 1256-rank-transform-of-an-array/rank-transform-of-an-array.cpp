class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0){
            return {};
        }
        map<int,int>m;
        vector<int>ans=arr;
        sort(ans.begin(),ans.end());
        int count=1;
        for(int i=0;i<ans.size();i++){
         if(m[ans[i]]==0){
            m[ans[i]]=count;
            count=count+1;
         }
        }
        for(int i=0;i<arr.size();i++ ){
            arr[i]=m[arr[i]];
        }
        return arr;
    }
};