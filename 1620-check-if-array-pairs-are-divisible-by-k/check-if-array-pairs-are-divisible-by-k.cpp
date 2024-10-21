class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>m;
        for(int i=0;i<arr.size();i++)
{
  m[(arr[i]%k +k)%k]++;
}  
  
           int ans=0;
                 if(m[0]%2==1){
    return false;
  }
             else{
                ans+=m[0]/2;
             }
             
            for(int i=1;i<=k/2;i++){
                 if(m[i]==m[k-i]){
                    ans+=m[i];
                 }
                 else{
                    return false;
                 }
            }
            
                return true;
            
        
  }
};