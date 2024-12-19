class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>compare=arr;
        sort(compare.begin(),compare.end());
        map<int,int>m1;
        map<int,int>m2;
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            m1[arr[i]]++;
            m2[compare[i]]++;
           
            if(m1==m2){
                count++;
            }
        }
        return count;
    }
};