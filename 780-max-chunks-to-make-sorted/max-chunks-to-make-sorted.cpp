class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int>compare;
        for(int i=0;i<n;i++){
            compare.push_back(i);
        }
        int x=0;
        int count=0;
        vector<int>v1;
        vector<int>v2;
        for(int i=0;i<arr.size();i++){
            v1.push_back(arr[i]);
            v2.push_back(compare[i]);
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            if(v1==v2){
                count++;
            }
        }
        return count;

    }
};