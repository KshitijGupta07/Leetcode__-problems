class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<long long>prefix;
        long long element=0;
        for(int i=0;i<nums.size();i++){
            element+=nums[i];
            prefix.push_back(element);
        }
        map<int,int>m;
        map<int,bool>check;
        for(int i=0;i<prefix.size();i++){
            m[prefix[i]%k]++;
        }
        for(int i=0;i<prefix.size()-1;i++){
            if(prefix[i]%k==prefix[i+1]%k){
                check[prefix[i]%k]=true;
            }
        }
        bool s=false;
        for(int i=0;i<prefix.size();i++){
           if( m[prefix[i]%k]>2){
            
            s=true;
            break;
           }
           if(m[prefix[i]%k]==2&&check[prefix[i]%k]==false){
            s=true;
            break;
           }
           if(prefix[i]%k==0&&i>0){
            s=true;
            break;
           }
        }
        if(s==true){
            return true;
        }
        
        return false;

    }
};