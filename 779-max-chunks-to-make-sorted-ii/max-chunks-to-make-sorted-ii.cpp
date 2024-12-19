class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>compare=arr;
        sort(compare.begin(),compare.end());
        vector<int>compare2;
        vector<int>compare3;
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            compare2.push_back(arr[i]);
            compare3.push_back(compare[i]);
            sort(compare2.begin(),compare2.end());
            sort(compare3.begin(),compare3.end());
            if(compare2==compare3){
                count++;
            }
        }
        return count;
    }
};