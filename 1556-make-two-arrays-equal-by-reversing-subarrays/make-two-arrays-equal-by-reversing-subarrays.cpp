class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>m;
        map<int,int>a;
        for(int i=0;i<target.size();i++){
            m[target[i]]++;
            a[target[i]]++;
            m[arr[i]]++;
        }
        for(int i=0;i<target.size();i++){
            if(a[target[i]]*2!=m[target[i]]){
                return false;
            }
        }
        
        return true;
    }
};