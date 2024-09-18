class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        map<int,bool>present;
        for(int i=0;i<arr.size();i++){
            int prev=0;
            int curr=arr[i];
            present[curr]=true;
            int j=i-1;
            while(j>=0&&prev!=curr){
                prev=(prev|arr[j]);
                curr=(curr|arr[j]);
                present[curr]=true;
                j--;
            }

        }
        return present.size();
    }
};