class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[(arr[i]%k+k)%k]++;
        }
        if(m[0]%2!=0){
            return false;
        }
        if(k%2==0){
            if(m[k/2]%2!=0){
                return false;
            }
        }
        
        for(int i=0;i<arr.size();i++){
            if(m[(arr[i]%k +k)%k]!=m[(k-(arr[i]%k +k)%k)%k]){
                return false;
            }
           
        }
        
        return true;
    }
};